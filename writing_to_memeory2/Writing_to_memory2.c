#include <Windows.h>
#include <stdio.h>

int main() {
	PVOID pAddress = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 100);

	CHAR* cString = "MalDev Academy Is The Best";

	memcpy(pAddress, cString, strlen(cString));

	printf("[+] Base address of allocated memory : 0x%p \n", pAddress);

	HeapFree(GetProcessHeap(), 0, pAddress);

	printf("[+] Press <Enter> to quit...");
	getchar();

	return 0;
}