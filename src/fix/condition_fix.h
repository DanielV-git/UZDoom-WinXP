#pragma once

#include <windows.h>
#include "lock_fix.h"

#undef InitializeConditionVariable
#undef WakeConditionVariable
#undef WakeAllConditionVariable
#undef SleepConditionVariableSRW
#undef SleepConditionVariableCS

#define InitializeConditionVariable XP_InitCV
#define WakeConditionVariable       XP_WakeCV
#define WakeAllConditionVariable    XP_WakeAllCV
#define SleepConditionVariableSRW   XP_SleepSRW
#define SleepConditionVariableCS    XP_SleepCS

static inline void __stdcall XP_InitCV(PCONDITION_VARIABLE cv) {
	cv->Ptr = CreateEvent(NULL, FALSE, FALSE, NULL);
}

static inline void __stdcall XP_WakeCV(PCONDITION_VARIABLE cv) {
	if (cv && cv->Ptr) SetEvent(cv->Ptr);
}

static inline void __stdcall XP_WakeAllCV(PCONDITION_VARIABLE cv) {
	if (cv && cv->Ptr) SetEvent(cv->Ptr);
}

static inline BOOL __stdcall XP_SleepSRW(PCONDITION_VARIABLE cv, PSRWLOCK srw, DWORD ms, ULONG flags) {
	ReleaseSRWLockExclusive(srw); // our own from lock_fix!
	DWORD r = WaitForSingleObject(cv->Ptr, ms);
	AcquireSRWLockExclusive(srw); // our own from lock_fix!
	return (r == WAIT_OBJECT_0);
}

static inline BOOL __stdcall XP_SleepCS(PCONDITION_VARIABLE cv, PCRITICAL_SECTION cs, DWORD ms) {
	LeaveCriticalSection(cs);
	DWORD r = WaitForSingleObject(cv->Ptr, ms);
	EnterCriticalSection(cs);
	return (r == WAIT_OBJECT_0);
}
