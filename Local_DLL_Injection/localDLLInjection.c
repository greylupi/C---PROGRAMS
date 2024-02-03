//can be used with the dll in this folder
//provide the dll name as argument

#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("[!] Missing Argument. Please provide the DLL to load. The DLL must be in the same folder. \n");
		return -1;
	}

	printf("[i] Injection of \"%s\" to process id: %d in progress...\n", argv[1], GetCurrentProcessId());

	printf("[+] Loading... ");

	if (LoadLibraryA(argv[1]) == NULL) {
		printf("[!] Failed to load DLL into process id: %d . Exited with error code: %d", GetCurrentProcessId(), GetLastError());
		return -1;
	}

	printf("[+] Injection executed. A message box should appear to confirm.\n");

	printf("[+} Press <Enter> to quit.");
	getchar();
	return 0;

}
