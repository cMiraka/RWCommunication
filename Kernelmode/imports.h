#pragma once

NTKERNELAPI
NTSTATUS
PsLookupProcessByProcessId(
	IN HANDLE ProcessId,
	OUT PEPROCESS* Process
);


NTKERNELAPI 
PVOID PsGetProcessSectionBaseAddress(
	IN PEPROCESS		Process
);

__declspec(dllimport) NTSTATUS __stdcall ZwQuerySystemInformation(SYSTEM_INFORMATION_CLASS, void*, unsigned long, unsigned long*);