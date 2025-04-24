//
// Created by Martin on 2025-04-24.
//

#include <stdio.h>
#include <windows.h>

int main () {
    //method 1 to allocate memory
    //PVOID pAddress = malloc(100);
    //method 2 to allocate memory
    PVOID pAddress = HeapAlloc (GetProcessHeap (), 0, 100);
    //method 3 to allocate memory
    //PVOID pAdress = LocalAlloc(LPTR, 100);

    printf("[+] Base address of allocated memory: 0x%p\n", pAddress);
    printf("[+] Press <Enter> to close program...");
    getchar();
    return 0;
}