#include <stdio.h>
#include <windows.h>


//Encryption Algorithm to be called. The function simply XORs each byte of the shellcode with a 1-byte key.
VOID XorByOneKey(IN PBYTE pData, IN SIZE_T sDataSize, IN BYTE bKey) {
	
	for (size_t i = 0; i < sDataSize; i++){
		pData[i] = pData[i] ^ bKey;
	}

}

//this will hold the data to be encrypted.
unsigned char Data[] = {
    "I am a string and will be encrypted using a simple XOR encryption algorithm"
};

unsigned char key[] = {
    0x68,0x6f,0x77,0x20,0x79,0x6f,0x75,0x20,0x64,0x6f,0x69,0x6e,0x67,0x3f
};

int main() {
    //the data is printed before encryption
    printf("[i] Address of Data: 0x%p \n", Data);
    printf("[i] Contents of Data: %s \n", Data);
    printf("Press enter to encrypt data");
    getchar();

    //encryption and print
    XorByOneKey(Data, sizeof(Data), key);
    printf("[i] Address of Data: 0x%p \n", Data);
    printf("[i] Encrypted Data contents: %s \n", Data);
    printf("Press enter to Decrypt data");
    getchar();

    //decrypt and print
    XorByOneKey(Data, sizeof(Data), key);
    printf("[i] Address of Data: 0x%p \n", Data);
    printf("[i] Decrypted Data contents: %s \n", Data);
    printf("Press enter to quit program");
    getchar();
    return 0;
}

