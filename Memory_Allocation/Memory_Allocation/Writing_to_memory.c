#include <Windows.h>
#include <stdio.h>

int main() {
	PVOID pAdress = HeapAlloc(GetProcessHeap(), 0, 100); 

	printf("[+] Base address of allocated memory: 0x%p \n", pAdress);
	printf("[+] Press <Enter> to quit...");
	getchar();

	return 0;

}