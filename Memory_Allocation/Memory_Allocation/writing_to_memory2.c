#include <Windows.h>
#include <stdio.h>

int main() {

	//HEAP_ZERO_MEMORY causes the allocated memory to be initialised to zero
	PVOID pAddress = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 100);

	CHAR* cString = "This is a cool program!";

	memcpy(pAddress, cString, strlen(cString));

	printf("[+] Base address of allocated memory: 0x%p \n", pAddress);

	//this free's the allocated memory, this avoids memory leaks
	HeapFree(GetProcessHeap(), 0, pAddress);


	printf("[+] Press <Enter> to quit...");
	getchar();

	return 0;

}