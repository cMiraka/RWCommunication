#pragma once
#include "structs.h"

#define ReadMemory 0x1337
#define WriteMemory 0x1337 + 0x8

class Communications {
private:
	HANDLE CurrentProcessHandle;
	HANDLE TargetProcessHandle;

public:

	Communications()
	{
		CurrentProcessHandle = GetCurrentProcess();
	}

	~Communications()
	{
		abort();
	}

	void SendRequest(MyStructure RequestStructure) {
		WriteProcessMemory(CurrentProcessHandle, &StructureInit, &RequestStructure, sizeof(MyStructure), 0);
	}

	void ReadMemoryDummy(){
		MyStructure Requests;
		Requests.myProcessID = 0;
		Requests.targetProcessID = 0;
		Requests.RequestID = ReadMemory;

		SendRequest(Requests);
	}

	void WriteMemoryDummy() {
		MyStructure Requests;
		Requests.myProcessID = 0;
		Requests.targetProcessID = 0;
		Requests.RequestID = WriteMemory;

		SendRequest(Requests);
	}

};