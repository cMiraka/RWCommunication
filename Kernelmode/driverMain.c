#include <ntddk.h>
#include "myntapi.h"
#include <minwindef.h>
#include "structs.h"
#include "imports.h"
#include "physmem.h"
#include "custom_crt.h"

#define dbg( content, ... ) DbgPrintEx( 0, 0, "[>] " content, __VA_ARGS__ )

DWORD64 GetProcessIdFromName(PWCHAR ProcName) {
	NTSTATUS result;
	PVOID infoBuffer = NULL;
	PSYSTEM_PROCESS_INFORMATION procSysInfo = NULL;
	ULONG retLen = 0;
	DWORD64 retVal = 0;

	result = ZwQuerySystemInformation(system_process_information, NULL, 0, &retLen);
	if (!retLen || result != 0xC0000004) {
		return 0;
	}

	while (result == 0xC0000004) {
		retLen += 0x1000;
		infoBuffer = ExAllocatePool(NonPagedPoolNx, retLen);
		if (infoBuffer == NULL) {
			return 0;
		}

		result = ZwQuerySystemInformation(system_process_information, infoBuffer, retLen, &retLen);
		if (!NT_SUCCESS(result)) {
			ExFreePool(infoBuffer);
			infoBuffer = NULL;
		}
	}

	if (!NT_SUCCESS(result)) {
		return 0;
	}

	procSysInfo = (PSYSTEM_PROCESS_INFORMATION)infoBuffer;

	while (procSysInfo) {
		if (procSysInfo->ImageName.Buffer != NULL) {
			if (RlWcsicmp(procSysInfo->ImageName.Buffer, ProcName, TRUE)) {
				retVal = (DWORD64)procSysInfo->UniqueProcessId;
				break;
			}
		}

		procSysInfo = procSysInfo->NextEntryOffset ? (PSYSTEM_PROCESS_INFORMATION)((PBYTE)procSysInfo + procSysInfo->NextEntryOffset) : NULL;
	}

	ExFreePool(infoBuffer);
	return retVal;
}


typedef struct _MyStructure
{
	int RequestID;
	int myProcessID;
	int targetProcessID;
} MyStructure, * PMyStructure;

typedef struct _CustomStructure {
	int RequestID;
	int myProcessID;
	int targetProcessID;
} CustomStructure, * PCustomStructure;

#define WriteMemory 0x1337 + 0x8

NTSTATUS CustomDriverEntry(
	_In_ PDRIVER_OBJECT  kdmapperParam1,
	_In_ PUNICODE_STRING kdmapperParam2

#define ReadMemory 0x1337
)
{
	UNREFERENCED_PARAMETER(kdmapperParam1);
	UNREFERENCED_PARAMETER(kdmapperParam2);

	DbgPrintEx(0, 0, "Hello world!");

	DWORD64 ProcessId = GetProcessIdFromName(L"Usermode.exe");
	dbg("ProcessId: %llu", ProcessId);

	PEPROCESS MyProcess;

	PsLookupProcessByProcessId(ProcessId, &MyProcess);

	PVOID ImageBase = PsGetProcessSectionBaseAddress(MyProcess);

	while (TRUE)
	{
		MyStructure ReadStruct;

		size_t Size = 0;
		ReadProcessMemory(ProcessId, (uintptr_t)ImageBase + 0x3630, &ReadStruct, sizeof(MyStructure), &Size);

		switch (ReadStruct.RequestID) {
		case ReadMemory:
			dbg("ReadMemory called!");

		case WriteMemory:
			dbg("WriteMemory called!");

		default:
			dbg("Zero calls!");
		}

	}

	return 0;
}