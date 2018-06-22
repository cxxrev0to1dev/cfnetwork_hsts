#include "cfnetwork_hsts/cfnetwork_hsts.h"

namespace CFNetworkHSTS{
	static HANDLE WINAPI ShellcodeBegin(PTHREAD_DATA parameter){
		if (!parameter)
			return (HANDLE)-3;
		if (parameter->fnRtlInitUnicodeString != nullptr&&parameter->fnLdrLoadDll != nullptr){
			UNICODE_STRING UnicodeString;
			parameter->fnRtlInitUnicodeString(&UnicodeString, parameter->dllpath);
			HANDLE module_handle = nullptr;
			return (HANDLE)parameter->fnLdrLoadDll(nullptr, nullptr, &UnicodeString, &module_handle);
		}
		else{
			return (HANDLE)-3;
		}
	}
	static DWORD WINAPI ShellcodeEnd(){
		return 0;
	}
	static bool SetProcessPrivilege(DWORD SE_DEBUG_PRIVILEGE = 0x14){
		BOOLEAN bl;
		RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &bl);
		return (bl==TRUE);
	}
	static bool ProcessInternalExecute(PTHREAD_DATA parameter, DWORD process_id){
		HANDLE hProcess = nullptr;
		CLIENT_ID cid = { (HANDLE)process_id, nullptr };
		OBJECT_ATTRIBUTES oa;
		InitializeObjectAttributes(&oa, NULL, 0, NULL, NULL);
		if (!NT_SUCCESS(NtOpenProcess(&hProcess, PROCESS_ALL_ACCESS, &oa, &cid))){
			return false;
		}
		PVOID data = VirtualAllocEx(hProcess, NULL, 0x2000, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		PVOID code = VirtualAllocEx(hProcess, NULL, 0x2000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (!data || !code){
			NtClose(hProcess);
			return false;
		}
		NtWriteVirtualMemory(hProcess, data, parameter, sizeof(THREAD_DATA), NULL);
		NtWriteVirtualMemory(hProcess, code, (PVOID)ShellcodeBegin, (ULONG)((LPBYTE)ShellcodeEnd - (LPBYTE)ShellcodeBegin), NULL);
		HANDLE hThread = nullptr;
		if (!NT_SUCCESS(RtlCreateUserThread(hProcess, NULL, FALSE, 0, 0, 0, code, data, &hThread, NULL))){
			NtClose(hProcess);
			return false;
		}
		NtWaitForSingleObject(hThread, FALSE, NULL);
		DWORD exit_code = -1;
		GetExitCodeThread(hThread, &exit_code);
		NtClose(hThread);
		VirtualFreeEx(hProcess, data, 0, MEM_RELEASE);
		VirtualFreeEx(hProcess, code, 0, MEM_RELEASE);
		NtClose(hProcess);
		return (exit_code == 0);
	}
	std::wstring GetAbsolutePath(const std::wstring& name){
		wchar_t fileName[MAX_PATH] = { 0 };
		GetModuleFileNameW(NULL, fileName, MAX_PATH);
		PathRemoveFileSpec(fileName);
		return std::wstring(fileName).append(name);
	}
	void SetThreadDllPath(PTHREAD_DATA parameter, const std::wstring& srcfile){
		wcscpy_s(parameter->dllpath, srcfile.c_str());
	}
	void InitializeThreadArg(THREAD_DATA* parameter){
		parameter->fnRtlInitUnicodeString = (pRtlInitUnicodeString)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "RtlInitUnicodeString");
		parameter->fnLdrLoadDll = (pLdrLoadDll)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "LdrLoadDll");
		parameter->fnGetTempPathW = (pGetTempPathW)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetTempPathW");
		parameter->fnGetSystemDirectoryW = (pGetSystemDirectoryW)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetSystemDirectoryW");
		parameter->fnGetVolumeInformationW = (pGetVolumeInformationW)GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetVolumeInformationW");
	}
	void Go(){
		PROCESSENTRY32W pe32;
		pe32.dwSize = sizeof(pe32);
		HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE)
			return;
		BOOL bMore = ::Process32FirstW(hProcessSnap, &pe32);
		while (bMore){
      if (!wcscmp(pe32.szExeFile, L"Impactor.exe")){
        THREAD_DATA parameter = { 0 };
        CFNetworkHSTS::InitializeThreadArg(&parameter);
        CFNetworkHSTS::SetProcessPrivilege();
        CFNetworkHSTS::SetThreadDllPath(&parameter, CFNetworkHSTS::GetAbsolutePath(L"\\cfnetwork_hook.dll"));
        CFNetworkHSTS::ProcessInternalExecute(&parameter, pe32.th32ProcessID);
      }
			bMore = ::Process32NextW(hProcessSnap, &pe32);
		}
		::CloseHandle(hProcessSnap);
	}
}
int wmain(int argc, wchar_t* argv[]){
  CFNetworkHSTS::Go();
	return 0;
}

