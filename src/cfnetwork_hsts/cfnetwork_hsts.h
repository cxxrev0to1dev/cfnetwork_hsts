#ifndef CFNETWORK_HSTS_H_
#define CFNETWORK_HSTS_H_

//////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstdint>
#include <string>
#include <Windows.h>
#include <Winternl.h>
#include <Tlhelp32.h>
#include <Shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")
//////////////////////////////////////////////////////////////////////////
typedef NTSTATUS(NTAPI *pRtlInitUnicodeString)(PUNICODE_STRING, PCWSTR);
typedef NTSTATUS(NTAPI *pLdrLoadDll)(PWCHAR, PULONG, PUNICODE_STRING, PHANDLE);
typedef DWORD(WINAPI *pGetTempPathW)(_In_ DWORD, LPWSTR);
typedef UINT(WINAPI* pGetSystemDirectoryW)(LPWSTR, UINT);
typedef BOOL(WINAPI *pGetVolumeInformationW)(LPCWSTR, LPWSTR, DWORD, LPDWORD, LPDWORD, LPDWORD, LPWSTR, DWORD);
typedef struct _THREAD_DATA{
	pRtlInitUnicodeString fnRtlInitUnicodeString;
	pLdrLoadDll fnLdrLoadDll;
	pGetTempPathW fnGetTempPathW;
	pGetSystemDirectoryW fnGetSystemDirectoryW;
	pGetVolumeInformationW fnGetVolumeInformationW;
	wchar_t dllpath[MAX_PATH];
}THREAD_DATA, *PTHREAD_DATA;
//////////////////////////////////////////////////////////////////////////
typedef struct _CLIENT_ID{
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

EXTERN_C NTSTATUS NTAPI RtlCreateUserThread(
	HANDLE,
	PSECURITY_DESCRIPTOR,
	BOOLEAN,
	ULONG,
	PULONG,
	PULONG,
	PVOID,
	PVOID,
	PHANDLE,
	PCLIENT_ID);
EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtOpenProcess(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PCLIENT_ID);
EXTERN_C NTSTATUS NTAPI NtWriteVirtualMemory(HANDLE, PVOID, PVOID, ULONG, PULONG);
EXTERN_C NTSTATUS NTAPI NtWaitForSingleObject(HANDLE, BOOLEAN, PLARGE_INTEGER);
EXTERN_C NTSTATUS NTAPI NtClose(HANDLE);
EXTERN_C NTSTATUS NTAPI CsrGetProcessId(void);
//////////////////////////////////////////////////////////////////////////

#endif