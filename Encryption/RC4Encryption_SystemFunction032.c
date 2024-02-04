#include <Windows.h>
#include <stdio.h>


//SystemFunction032 is an undocumented API; however information about it can be found here: https://source.winehq.org/WineAPI/SystemFunction032.html
// 
// Defining a USTRING struct
// This is what SystemFunction032 function take as parameters
typedef struct
{
	DWORD	Length;
	DWORD	MaximumLength;
	PVOID	Buffer;

} USTRING;

typedef NTSTATUS(NTAPI* fnSystemFunction032)(
	struct USTRING* Data,
	struct USTRING* Key
	);

BOOL Rc4EncryptionViSystemFunc032(IN PBYTE pRc4Key, IN PBYTE pPayloadData, IN DWORD dwRc4KeySize, IN DWORD sPayloadSize) {

	NTSTATUS	STATUS = NULL;

	USTRING		Key = { .Buffer = pRc4Key, 		.Length = dwRc4KeySize,		.MaximumLength = dwRc4KeySize },
		Data = { .Buffer = pPayloadData, 	.Length = sPayloadSize,		.MaximumLength = sPayloadSize };

	fnSystemFunction032 SystemFunction032 = (fnSystemFunction032)GetProcAddress(LoadLibraryA("Advapi32"), "SystemFunction032");

	if ((STATUS = SystemFunction032(&Data, &Key)) != 0x0) {
		printf("[!] SystemFunction032 FAILED With Error: 0x%0.8X \n", STATUS);
		return FALSE;
	}

	return TRUE;
}

unsigned char shellcode[] = {
	"The string to encrypt."
};

unsigned char key[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};


int main() {

	printf("[i] shellcode : 0x%p \n", shellcode);

	if (!Rc4EncryptionViSystemFunc032(key, shellcode, sizeof(key), sizeof(shellcode))) {
		return -1;
	}

	printf("[#] Press <Enter> To Decrypt ...");
	getchar();

	if (!Rc4EncryptionViSystemFunc032(key, shellcode, sizeof(key), sizeof(shellcode))) {
		// Failed
		return -1;
	}
	printf("[i] shellcode : \"%s\" \n", (char*)shellcode);

	printf("[#] Press <Enter> To Quit ...");
	getchar();
	return 0;

}
