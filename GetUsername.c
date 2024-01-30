#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <Lmcons.h>
using namespace std;

int main()
{
    TCHAR name [UNLEN + 1];
    DWORD size = UNLEN + 1;

    if (GetUserName(name, &size)) {
        printf("Username: %s \n", name);
    }
    else {
        printf("Failed to retrieve the username. Error code %d \n", GetLastError());
    }
	//initialize variable
	HANDLE hFile = INVALID_HANDLE_VALUE;

	//full path of file to create
	LPCWSTR filePath = L"C:\\users\\marti\\desktop\\test.txt";
	//call createfile... parameters from documentation
	hFile = CreateFileW(filePath, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// On failure CreateFileW returns INVALID_HANDLE_VALUE
	// GetLastError() is another Windows API that retrieves the error code of the previously executed WinAPI function
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("[-] CreateFileW Api Function Failed With Error: %d\n", GetLastError());
		return -1;
	}
}
