#pragma once

#include <windows.h>

#undef InitializeSRWLock
#undef AcquireSRWLockExclusive
#undef ReleaseSRWLockExclusive

#define InitializeSRWLock           XP_InitSRW
#define AcquireSRWLockExclusive     XP_AcquireSRW
#define ReleaseSRWLockExclusive     XP_ReleaseSRW

static inline void __stdcall XP_InitSRW(PSRWLOCK lock) {
	PCRITICAL_SECTION cs = (PCRITICAL_SECTION)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(CRITICAL_SECTION));
	if (cs) InitializeCriticalSection(cs);
	lock->Ptr = cs;
}

static inline void __stdcall XP_AcquireSRW(PSRWLOCK lock) {
	if (lock && lock->Ptr) EnterCriticalSection((PCRITICAL_SECTION)lock->Ptr);
}

static inline void __stdcall XP_ReleaseSRW(PSRWLOCK lock) {
	if (lock && lock->Ptr) LeaveCriticalSection((PCRITICAL_SECTION)lock->Ptr);
}
