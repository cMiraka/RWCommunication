#pragma once

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

MyStructure StructureInit;

#define ReadMemoryCode		0x80000007
#define WriteMemoryCode		 0x80000008