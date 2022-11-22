#include <iostream>
#include <Windows.h>
#include "communications.h"

int main()
{
    Communications Entry = Communications();

    StructureInit.myProcessID = 78;
    StructureInit.RequestID = 78;
    StructureInit.targetProcessID = 78;

    while (1)
    {
        printf("RequestId: %i\n", StructureInit.RequestID);
        printf("myProcessID: %i\n", StructureInit.myProcessID);
        printf("targetProcessID: %i\n", StructureInit.targetProcessID);

        if (GetAsyncKeyState(VK_F1))
            Entry.ReadMemoryDummy();

        if (GetAsyncKeyState(VK_F2))
            Entry.WriteMemoryDummy();
    }
}