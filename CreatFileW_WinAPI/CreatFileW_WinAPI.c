#include <windows.h>
#include <stdio.h>


int main() {

	//tHIS is needed to store the handle to the file object
	//the 'INVALID_HANDLE_VALUE' is to initialize the variable
	HANDLE hFile = INVALID_HANDLE_VALUE; //initialize variable

	// The full path of the file to create.
	// Double backslashes are required to escape the single backslash character in C
	LPCWSTR filepath = L"C:\\Users\\Martin\\OneDrive\\Desktop\\Test.txt";


	//CALL createfilew with the filepath
	// the additonal parameters are directly from the documentation
	hFile = CreateFileW(filepath, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	//on failure creatfilew returns INVALID_HANDLE_VALUE
	//GetLastError() is another windows API that retrieves the error code of the previously executed WinAPI function
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("[-] CreateFileW API function failed with error: %d\n", GetLastError);
		return -1;
	}

}