#include <cstdio>
#include <windows.h>

typedef char*(*encrypt_t)(char*, int);

typedef char*(*decrypt_t)(char*, int);

int main() {
    HINSTANCE handle = LoadLibrary(TEXT("./lib.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE){
        printf("Lib not found\n");
        return 1;
    }

    encrypt_t encrypt = (encrypt_t)GetProcAddress(handle, TEXT("encrypt"));

    if (encrypt == nullptr) {
        printf("Function not found!\n");
        return -1;
    }

    decrypt_t decrypt = (decrypt_t)GetProcAddress(handle, TEXT("decrypt"));

    if (decrypt == nullptr) {
        printf("Function not found!\n");
        return -1;
    }

    char myText[] = "Roses are yellow, violets are green!!!";

    char* result = encrypt(myText,1);
    printf("%s\n", result);

    char* result2 = decrypt(result, 1);
    printf("%s\n", result2);
}

/*
 * gcc -c lib.cpp -o lib.obj
 * gcc lib.obj -shared -o lib.dll
 * gcc -c main.cpp -o main.obj
 * gcc -o main main.obj -L. lib.dll
*/


