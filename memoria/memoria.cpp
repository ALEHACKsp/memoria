#include "memoria.hpp"

#include <string>
#include <Windows.h>

// --- Handle Methods + PID ---
HWND Memoria::GetWindowHandle(LPCSTR wName)
{
	HWND wHandle = FindWindowA(0, wName); // get handle to top level window
	return wHandle;
}

DWORD Memoria::GetProcessId(HWND wHandle)
{
	DWORD pid;
	GetWindowThreadProcessId(wHandle, &pid); // get the process id using window handle
	return pid;
}

HANDLE Memoria::GetProcessHandle(DWORD pid, DWORD access)
{
	// access: (https://docs.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights)
	HANDLE pHandle = OpenProcess(access, FALSE, pid); // get process handle
	return pHandle;
}

// --- Reading Memory ---
int Memoria::ReadInt(HANDLE pHandle, DWORD address)
{
	int val;
	ReadProcessMemory(pHandle, (void*)address, &val, sizeof(val), 0);
	return val;
}
