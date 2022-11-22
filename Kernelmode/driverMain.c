#include <ntddk.h>

#include <minwindef.h>
#include "structs.h"
#include "myntapi.h"
#include "imports.h"
#include "custom_crt.h"
#include "physmem.h"

void MainThread() 
{
	NTSTATUS Status = STATUS_UNSUCCESSFUL;

	DWORD64 ProcessId = GetProcessIdFromName(L"Usermode.exe");
	dbg("ProcessId: %llu", ProcessId);

	for (;;)
	{
		while (ProcessId == 0)
			ProcessId = GetProcessIdFromName(L"Usermode.exe");

		PEPROCESS MyProcess;

		Status = PsLookupProcessByProcessId(ProcessId, &MyProcess);

		if (!NT_SUCCESS(Status))
			break;

		PVOID ImageBase = PsGetProcessSectionBaseAddress(MyProcess);

		MyStructure ReadStruct;

		size_t Size = 0;
		ReadProcessMemory(ProcessId, (uintptr_t)ImageBase + 0x3630, &ReadStruct, sizeof(MyStructure), &Size);

		if (ReadStruct.RequestID == ReadMemoryCode) {
			dbg("ReadMemory Called!");
		}
		else if (ReadStruct.RequestID == WriteMemoryCode) {
			dbg("WriteMemory Called!");
		}
	}
}

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT Param1, _In_ PUNICODE_STRING Param2)
{
	UNREFERENCED_PARAMETER(Param1); UNREFERENCED_PARAMETER(Param2);

	dbg("At entry!");

	HANDLE thread_handle = NULL;
	OBJECT_ATTRIBUTES object_attribues;
	InitializeObjectAttributes(&object_attribues, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);

	NTSTATUS status = PsCreateSystemThread(&thread_handle, 0, &object_attribues, NULL, NULL, &MainThread, NULL);

	return STATUS_UNSUCCESSFUL;
}