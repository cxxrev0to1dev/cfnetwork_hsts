#ifndef CFNETWORK_HSTS_CFNETWORK_HOOK_H_
#define CFNETWORK_HSTS_CFNETWORK_HOOK_H_

#include <Windows.h>

#ifdef CFNETWORK_HOOK_EXPORTS
#define CFNETWORK_HOOK_API __declspec(dllexport)
#else
#define CFNETWORK_HOOK_API __declspec(dllimport)
#endif

#endif