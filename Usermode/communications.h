#pragma once
#include "structs.h"


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
		Requests.myProcessID = 1337;
		Requests.targetProcessID = 1337;
		Requests.RequestID = ReadMemoryCode;

		SendRequest(Requests);
	}

	void WriteMemoryDummy() {
		MyStructure Requests;
		Requests.myProcessID = 1337;
		Requests.targetProcessID = 1337;
		Requests.RequestID = WriteMemoryCode;

		SendRequest(Requests);
	}

};