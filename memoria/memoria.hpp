#pragma once

#include <string>

#include <Windows.h>


class Memoria
{
public:
	// handle methods + pid
	HWND GetWindowHandle(LPCSTR wName);
	DWORD GetProcessId(HWND wHandle);
	HANDLE GetProcessHandle(DWORD pid, DWORD access = PROCESS_ALL_ACCESS);

	// reading methods
	int ReadInt(HANDLE pHandle, DWORD address);

	// writing methods
};

