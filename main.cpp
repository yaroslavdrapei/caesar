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
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl /c /EHsc .\lib.cpp'
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl /LD .\lib.cpp /link'
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl /c /EHsc .\main.cpp'
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl main.obj /link'
*/


