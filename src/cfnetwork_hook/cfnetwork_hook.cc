#include "cfnetwork_hook/cfnetwork_hook.h"
#include <cassert>
#include <string>
#include <fstream>
#include <detours.h>
#include <atlconv.h>
#include <cstdint>
#include <winternl.h>
#define HOOK_WINHTTP
#ifdef HOOK_ITUNES
#pragma comment(lib,"CFNetwork.lib")
#pragma comment(lib,"CoreFoundation.lib")
#include <CFNetwork/CFHTTPMessage.h>
#elif defined(HOOK_WINHTTP)
#include <winhttp.h>
#pragma comment(lib,"winhttp.lib")
#else
#include <WinInet.h>
#pragma comment(lib, "wininet.lib")
#endif

namespace IEProxy{
  void FreeConfig(WINHTTP_CURRENT_USER_IE_PROXY_CONFIG* config){
    if (config->lpszAutoConfigUrl)
      GlobalFree(config->lpszAutoConfigUrl);
    if (config->lpszProxy)
      GlobalFree(config->lpszProxy);
    if (config->lpszProxyBypass)
      GlobalFree(config->lpszProxyBypass);
  }

  void FreeInfo(WINHTTP_PROXY_INFO* info){
    if (info->lpszProxy)
      GlobalFree(info->lpszProxy);
    if (info->lpszProxyBypass)
      GlobalFree(info->lpszProxyBypass);
  }
  bool ConfigureSSL(HINTERNET internet){
    DWORD protocols = 0;
    protocols |= WINHTTP_FLAG_SECURE_PROTOCOL_SSL2;
    protocols |= WINHTTP_FLAG_SECURE_PROTOCOL_SSL3;
    protocols |= WINHTTP_FLAG_SECURE_PROTOCOL_TLS1;
    protocols |= WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_1;
    protocols |= WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_2;
    BOOL rv = WinHttpSetOption(internet, WINHTTP_OPTION_SECURE_PROTOCOLS, &protocols, sizeof(protocols));
    return (rv == TRUE);
  }
  bool ApplyProxy(HINTERNET internet, const wchar_t* proxy_str, bool is_direct){
    WINHTTP_PROXY_INFO pi;
    if (is_direct){
      pi.dwAccessType = WINHTTP_ACCESS_TYPE_NO_PROXY;
      pi.lpszProxy = WINHTTP_NO_PROXY_NAME;
      pi.lpszProxyBypass = WINHTTP_NO_PROXY_BYPASS;
    }
    else{
      pi.dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;
      pi.lpszProxy = const_cast<LPWSTR>(proxy_str);
      pi.lpszProxyBypass = WINHTTP_NO_PROXY_BYPASS;
    }
    BOOL rv = WinHttpSetOption(internet, WINHTTP_OPTION_PROXY, &pi, sizeof(pi));
    return (rv == TRUE);
  }

  bool ConfigureProxy(HINTERNET internet){
    WINHTTP_CURRENT_USER_IE_PROXY_CONFIG ie_config = { 0 };
    if (!WinHttpGetIEProxyConfigForCurrentUser(&ie_config)){
      return false;
    }
    WINHTTP_AUTOPROXY_OPTIONS options = { 0 };
    options.fAutoLogonIfChallenged = TRUE;
    if (ie_config.fAutoDetect){
      options.lpszAutoConfigUrl = ie_config.lpszAutoConfigUrl;
      options.dwFlags = WINHTTP_AUTOPROXY_CONFIG_URL;
    }
    else{
      options.dwFlags = WINHTTP_AUTOPROXY_AUTO_DETECT;
      options.dwAutoDetectFlags = WINHTTP_AUTO_DETECT_TYPE_DHCP | WINHTTP_AUTO_DETECT_TYPE_DNS_A;
    }
    std::wstring query_url(L"http://www.baidu.com");
    WINHTTP_PROXY_INFO info = { 0 };
    BOOL rv = WinHttpGetProxyForUrl(internet, query_url.c_str(), &options, &info);
    WINHTTP_PROXY_INFO pi;
    switch (info.dwAccessType){
    case WINHTTP_ACCESS_TYPE_NO_PROXY:
      ApplyProxy(internet, NULL, TRUE);
      break;
    case WINHTTP_ACCESS_TYPE_NAMED_PROXY:
      ApplyProxy(internet, ie_config.lpszProxy, FALSE);
      break;
    default:
      pi.dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;
      pi.lpszProxy = ie_config.lpszProxy;
      pi.lpszProxyBypass = ie_config.lpszProxyBypass;
      rv = WinHttpSetOption(internet, WINHTTP_OPTION_PROXY, &pi, sizeof(pi));
      break;
    }
    FreeConfig(&ie_config);
    FreeInfo(&info);
    return (rv == TRUE);
  }
//   bool ConfigureProxy(HINTERNET request){
//     WINHTTP_PROXY_INFO proxyInfo = { 0 };
//     proxyInfo.lpszProxy = new WCHAR[PROXY_STR_MAX_LEN];
//     proxyInfo.lpszProxyBypass = new WCHAR[PROXY_STR_MAX_LEN];
//     proxyInfo.dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;
//     swprintf_s(proxyInfo.lpszProxy, PROXY_STR_MAX_LEN, proxy.proxyStr);
//     swprintf_s(proxyInfo.lpszProxyBypass, PROXY_STR_MAX_LEN, proxy.proxyPassBy); // *.local;<local>
// 
//     BOOL rv = WinHttpSetOption(request, WINHTTP_OPTION_PROXY, &proxyInfo, sizeof(proxyInfo));
//     delete[] proxyInfo.lpszProxy;
//     delete[] proxyInfo.lpszProxyBypass;
// 
//     //DWORD dw = sizeof(proxyInfo);
//     //WinHttpQueryOption(request, WINHTTP_OPTION_PROXY, &proxyInfo, &dw);
//     return rv;
//   }

}
#ifdef HOOK_ITUNES
CFHTTPMessageRef (*OldCFHTTPMessageCreateRequest)(CFAllocatorRef alloc,
	CFStringRef requestMethod, CFURLRef url, CFStringRef httpVersion) = CFHTTPMessageCreateRequest;
CFHTTPMessageRef NewCFHTTPMessageCreateRequest(CFAllocatorRef alloc,
	CFStringRef requestMethod,CFURLRef url,CFStringRef httpVersion){
	if (OldCFHTTPMessageCreateRequest != nullptr){
		char url_out[1024] = {0};
		if (CFStringGetCString(CFURLGetString(url), url_out, 1024, kCFStringEncodingUTF8)){
			std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
			outfile.write(url_out, strlen(url_out));
			outfile.write("\r\n\r\n", 4);
			outfile.close();
		}
			OutputDebugStringA(url_out);
		return OldCFHTTPMessageCreateRequest(alloc, requestMethod, url, httpVersion);
	}
	return nullptr;
}
void(*OldCFHTTPMessageSetBody)(CFHTTPMessageRef message, CFDataRef bodyData) = CFHTTPMessageSetBody;
void NewCFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData){
	if (OldCFHTTPMessageSetBody != nullptr){
		const UInt8* data = CFDataGetBytePtr(bodyData);
		const CFIndex length = CFDataGetLength(bodyData);
		if (length){
			std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
			outfile.write((char*)data, length);
			outfile.write("\r\n\r\n", 4);
			outfile.close();
		}
		OldCFHTTPMessageSetBody(message, bodyData);
	}
}
#elif defined(HOOK_WINHTTP)
BOOL(WINAPI* OldWinHttpSendRequest)(
  _In_     HINTERNET hRequest,
  _In_opt_ LPCWSTR   pwszHeaders,
  _In_     DWORD     dwHeadersLength,
  _In_opt_ LPVOID    lpOptional,
  _In_     DWORD     dwOptionalLength,
  _In_     DWORD     dwTotalLength,
  _In_     DWORD_PTR dwContext
  ) = WinHttpSendRequest;
BOOL WINAPI NewWinHttpSendRequest(
  _In_     HINTERNET hRequest,
  _In_opt_ LPCWSTR   pwszHeaders,
  _In_     DWORD     dwHeadersLength,
  _In_opt_ LPVOID    lpOptional,
  _In_     DWORD     dwOptionalLength,
  _In_     DWORD     dwTotalLength,
  _In_     DWORD_PTR dwContext
  ){
  USES_CONVERSION;
  std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
  outfile.write((char*)W2A(pwszHeaders), dwHeadersLength);
  outfile.write("\r\n\r\n", 4);
  outfile.close();
  if (dwOptionalLength){
    std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
    outfile.write((char*)lpOptional, dwOptionalLength);
    outfile.write("\r\n\r\n", 4);
    outfile.close();
  }
  return OldWinHttpSendRequest(hRequest, pwszHeaders, dwHeadersLength, lpOptional, dwOptionalLength, dwTotalLength, dwContext);
}
HINTERNET(WINAPI* OldWinHttpOpenRequest)(
  _In_ HINTERNET hConnect,
  _In_ LPCWSTR   pwszVerb,
  _In_ LPCWSTR   pwszObjectName,
  _In_ LPCWSTR   pwszVersion,
  _In_ LPCWSTR   pwszReferrer,
  _In_ LPCWSTR   *ppwszAcceptTypes,
  _In_ DWORD     dwFlags
  ) = WinHttpOpenRequest;
HINTERNET WINAPI NewWinHttpOpenRequest(
  _In_ HINTERNET hConnect,
  _In_ LPCWSTR   pwszVerb,
  _In_ LPCWSTR   pwszObjectName,
  _In_ LPCWSTR   pwszVersion,
  _In_ LPCWSTR   pwszReferrer,
  _In_ LPCWSTR   *ppwszAcceptTypes,
  _In_ DWORD     dwFlags
  ){
  HINTERNET result = OldWinHttpOpenRequest(hConnect, pwszVerb, pwszObjectName, pwszVersion, pwszReferrer, ppwszAcceptTypes, dwFlags);
  IEProxy::ConfigureSSL(result);
  IEProxy::ConfigureProxy(result);
  return result;
}
#else
BOOL(WINAPI* OldHttpSendRequest)(
  _In_ HINTERNET hRequest,
  _In_ LPCTSTR   lpszHeaders,
  _In_ DWORD     dwHeadersLength,
  _In_ LPVOID    lpOptional,
  _In_ DWORD     dwOptionalLength
  ) = HttpSendRequest;
BOOL WINAPI NewHttpSendRequest(
  _In_ HINTERNET hRequest,
  _In_ LPCTSTR   lpszHeaders,
  _In_ DWORD     dwHeadersLength,
  _In_ LPVOID    lpOptional,
  _In_ DWORD     dwOptionalLength
  ){
  USES_CONVERSION;
  std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
  outfile.write((char*)W2A(lpszHeaders), wcslen(lpszHeaders));
  outfile.write("\r\n\r\n", 4);
  outfile.close();
  if (dwOptionalLength){
    std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
    outfile.write((char*)lpOptional, dwOptionalLength);
    outfile.write("\r\n\r\n", 4);
    outfile.close();
  }
  return OldHttpSendRequest(hRequest, lpszHeaders, dwHeadersLength, lpOptional, dwOptionalLength);
}
#endif
void(*old_plist_to_xml)(void* plist, char **plist_xml, std::uint32_t* length);
void(*old_plist_to_bin)(void* plist, char **plist_bin, std::uint32_t* length);
void(*old_plist_from_xml)(const char *plist_xml, std::uint32_t length, void* plist);
void(*old_plist_from_bin)(const char *plist_bin, std::uint32_t length, void* plist);
void(*old_plist_from_memory)(const char *plist_data, std::uint32_t length, void* plist);
void new_plist_to_xml(void* plist, char **plist_xml, std::uint32_t* length){
  old_plist_to_xml(plist, plist_xml, length);
  if (*length){
    std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
    outfile.write(*plist_xml, *length);
    outfile.write("\r\n\r\n", 4);
    outfile.close();
  }
}
void new_plist_to_bin(void* plist, char **plist_bin, std::uint32_t* length){
  old_plist_to_bin(plist, plist_bin, length);
}
void new_plist_from_xml(const char *plist_xml, std::uint32_t length, void* plist){
  old_plist_from_xml(plist_xml, length, plist);
  if (length){
    std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
    outfile.write(plist_xml, length);
    outfile.write("\r\n\r\n", 4);
    outfile.close();
  }
}
void new_plist_from_bin(const char *plist_bin, std::uint32_t length, void* plist){
  old_plist_from_bin(plist_bin, length, plist);
}
void new_plist_from_memory(const char *plist_data, std::uint32_t length, void* plist){
  old_plist_from_memory(plist_data, length, plist);
}
static std::size_t(*old_Curl_ossl_send)(void* conn, int sockindex, const void *mem, size_t len) = (std::size_t(*)(void*, int, const void*, size_t))0x5F176A;
static std::size_t(*old_Curl_ossl_recv)(void* conn, int num, char *buf, size_t buffersize, bool *wouldblock) = (std::size_t(*)(void*, int, char*, size_t, bool*))0x5F167C;
static void Log(const char* s, std::size_t len){
  if (len){
    if (strstr(s,"com.apple.developer.team-identifier")!=nullptr){
      _asm int 3
    }
    std::ofstream outfile("F:\\cfnetwork_hsts\\Release\\new.txt", std::ofstream::binary | std::ofstream::app);
    outfile.write((char*)s, len);
    outfile.write("\r\n\r\n", 4);
    outfile.close();
  }
}
DWORD esp_reg = 0;
std::size_t len111 = 0;
__declspec(naked) void new_Curl_ossl_send(void* conn, int sockindex, const void *mem, size_t len){
  _asm pop esp_reg
  _asm call old_Curl_ossl_send
  _asm pushad
  _asm mov len111, eax
  Log((const char*)mem, len);
  _asm popad
  _asm mov eax, len111;
  _asm push esp_reg
  _asm retn
}
__declspec(naked) std::size_t new_Curl_ossl_recv(void* conn, int num, char *buf, size_t buffersize, bool *wouldblock){
  _asm pop esp_reg
  _asm call old_Curl_ossl_recv
  _asm pushad
  _asm mov len111, eax
  Log((const char*)buf, len111);
  _asm popad
  _asm mov eax, len111;
  _asm push esp_reg
  _asm retn
}
FARPROC GetAddress(const char* function_name){
#ifdef OS_WIN_64
  PPEB lpPeb = (PPEB)__readgsqword(0x60);
#else
  PPEB lpPeb = (PPEB)__readfsdword(0x30);
#endif
  PLIST_ENTRY pListHead = &lpPeb->Ldr->InMemoryOrderModuleList;
  PLIST_ENTRY pListEntry = pListHead->Flink;
  while (pListEntry != pListHead){
    PLDR_DATA_TABLE_ENTRY pModEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
    if (pModEntry->FullDllName.Length){
      FARPROC address = GetProcAddress(LoadLibraryW(pModEntry->FullDllName.Buffer), function_name);
      if (address){
        return address;
      }
    }
    pListEntry = pListEntry->Flink;
  }
  return nullptr;
}
void HookPListOn(){
  DetourTransactionBegin();
  DetourUpdateThread(GetCurrentThread());
  old_plist_to_xml = (void(*)(void*,char**,std::uint32_t*))GetAddress("plist_to_xml");
  DetourAttach(&(PVOID&)old_plist_to_xml, new_plist_to_xml);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_to_xml detoured successfully", "DetourAttach successfully", MB_OK);
  DetourTransactionBegin();
  old_plist_to_bin = (void(*)(void*, char**, std::uint32_t*))GetAddress("plist_to_bin");
  DetourAttach(&(PVOID&)old_plist_to_bin, new_plist_to_bin);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_to_bin detoured successfully", "DetourAttach successfully", MB_OK);
  DetourTransactionBegin();
  old_plist_from_xml = (void(*)(const char*, std::uint32_t, void*))GetAddress("plist_from_xml");
  DetourAttach(&(PVOID&)old_plist_from_xml, new_plist_from_xml);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_from_xml detoured successfully", "DetourAttach successfully", MB_OK);
  DetourTransactionBegin();
  old_plist_from_bin = (void(*)(const char*, std::uint32_t, void*))GetAddress("plist_from_bin");
  DetourAttach(&(PVOID&)old_plist_from_bin, new_plist_from_bin);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_from_bin detoured successfully", "DetourAttach successfully", MB_OK);
  DetourTransactionBegin();
  old_plist_from_memory = (void(*)(const char*, std::uint32_t, void*))GetAddress("plist_from_memory");
  DetourAttach(&(PVOID&)old_plist_from_memory, new_plist_from_memory);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_from_memory detoured successfully", "DetourAttach successfully", MB_OK);
  DetourTransactionBegin();
}
void HookPlistOff(){
  DetourTransactionBegin();
  DetourUpdateThread(GetCurrentThread());
  DetourDetach(&(PVOID&)old_plist_to_xml, new_plist_to_xml);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_to_xml detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
  DetourDetach(&(PVOID&)old_plist_to_bin, new_plist_to_bin);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_to_bin detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
  DetourDetach(&(PVOID&)old_plist_from_xml, new_plist_from_xml);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_from_xml detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
  DetourDetach(&(PVOID&)old_plist_from_bin, new_plist_from_bin);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_from_bin detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
  DetourDetach(&(PVOID&)old_plist_from_memory, new_plist_from_memory);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_plist_from_memory detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
}
void HookCUrlOn(){
  DetourTransactionBegin();
  DetourUpdateThread(GetCurrentThread());
  *(DWORD*)(&old_Curl_ossl_send) = (DWORD)0x5F176A;
  DetourAttach(&(PVOID&)old_Curl_ossl_send, new_Curl_ossl_send);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_Curl_ossl_send detoured successfully", "DetourAttach successfully", MB_OK);
  DetourTransactionBegin();
  *(DWORD*)(&old_Curl_ossl_recv) = (DWORD)0x5F167C;
  DetourAttach(&(PVOID&)old_Curl_ossl_recv, new_Curl_ossl_recv);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_Curl_ossl_recv detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
}
void HookCUrlOff(){
  DetourTransactionBegin();
  DetourUpdateThread(GetCurrentThread());
  DetourDetach(&(PVOID&)old_Curl_ossl_send, new_Curl_ossl_send);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_Curl_ossl_send detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
  DetourDetach(&(PVOID&)old_Curl_ossl_recv, new_Curl_ossl_recv);
  if (DetourTransactionCommit() == NO_ERROR)
    MessageBoxA(GetActiveWindow(), "new_Curl_ossl_recv detoured successfully", "DetourDetach successfully", MB_OK);
  DetourTransactionBegin();
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved){
	if (ul_reason_for_call == DLL_PROCESS_ATTACH){
		DisableThreadLibraryCalls(hModule);
    //HookPListOn();
    HookCUrlOn();
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
#ifdef HOOK_ITUNES
		DetourAttach(&(PVOID&)OldCFHTTPMessageCreateRequest, NewCFHTTPMessageCreateRequest);
		if (DetourTransactionCommit() == NO_ERROR)
			OutputDebugStringA("CFHTTPMessageCreateRequest detoured successfully");
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)OldCFHTTPMessageSetBody, NewCFHTTPMessageSetBody);
		if (DetourTransactionCommit() == NO_ERROR)
			OutputDebugStringA("CFHTTPMessageSetBody detoured successfully");
#elif defined(HOOK_WINHTTP)
//     DetourAttach(&(PVOID&)OldWinHttpSendRequest, NewWinHttpSendRequest);
//     if (DetourTransactionCommit() == NO_ERROR)
//       MessageBoxA(GetActiveWindow(),"OldWinHttpSendRequest detoured successfully","DetourAttach successfully",MB_OK);
//     DetourTransactionBegin();
    DetourAttach(&(PVOID&)OldWinHttpOpenRequest, NewWinHttpOpenRequest);
    if (DetourTransactionCommit() == NO_ERROR)
      MessageBoxA(GetActiveWindow(),"NewWinHttpOpenRequest detoured successfully","DetourAttach successfully",MB_OK);
    DetourTransactionBegin();
#else
    DetourAttach(&(PVOID&)OldHttpSendRequest, NewHttpSendRequest);
    if (DetourTransactionCommit() == NO_ERROR)
      MessageBoxA(GetActiveWindow(), "NewHttpSendRequest detoured successfully", "DetourAttach successfully", MB_OK);
    DetourTransactionBegin();
#endif
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH){
    //HookPlistOff();
    HookCUrlOff();
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
#ifdef HOOK_ITUNES
		DetourDetach(&(PVOID&)OldCFHTTPMessageCreateRequest, NewCFHTTPMessageCreateRequest);
		if (DetourTransactionCommit() == NO_ERROR)
			OutputDebugStringA("CFHTTPMessageCreateRequest detoured successfully");
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)OldCFHTTPMessageSetBody, NewCFHTTPMessageSetBody);
		if (DetourTransactionCommit() == NO_ERROR)
			OutputDebugStringA("CFHTTPMessageSetBody detoured successfully");
#elif defined(HOOK_WINHTTP)
    DetourDetach(&(PVOID&)OldWinHttpSendRequest, NewWinHttpSendRequest);
    if (DetourTransactionCommit() == NO_ERROR)
      MessageBoxA(GetActiveWindow(), "OldWinHttpSendRequest detoured successfully", "DetourDetach successfully", MB_OK);
    DetourTransactionBegin();
#else
    DetourDetach(&(PVOID&)OldHttpSendRequest, NewHttpSendRequest);
    if (DetourTransactionCommit() == NO_ERROR)
      MessageBoxA(GetActiveWindow(), "NewHttpSendRequest detoured successfully", "DetourDetach successfully", MB_OK);
    DetourTransactionBegin();
#endif
	}
	return TRUE;
}