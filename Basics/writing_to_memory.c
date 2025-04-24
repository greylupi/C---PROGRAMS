//
// Created by Martin on 2025-04-24.
//

#include <stdio.h>
#include <windows.h>

int main() {

    PVOID pAddress = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 100);
    CHAR* cString = "This string will be saved in the allocated memory";

    //memcpy is used here to copy the string to memory
    memcpy(pAddress, cString, strlen(cString));

    printf("[+] Base address of allocated memory: 0x%p\n", pAddress);
    printf("[+] Press <Enter> to close program...");
    getchar();

    return 0;

}