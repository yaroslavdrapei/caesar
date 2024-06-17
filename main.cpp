#include <cstdio>
#include "lib.h"

int main() {
    char myText[] = "Roses are yellow, violets are green!!!";

    char* result = encrypt(myText,1);
    printf("%s\n", result);

    char* result2 = decrypt(result, 1);
    printf("%s\n", result2);
}

// Dynamic:

/*
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl /c /EHsc .\lib.cpp'
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl /LD .\lib.obj /link'
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl /c /EHsc .\main.cpp'
 * cmd /c '"D:\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd.bat" && cl main.obj /link'
*/

// Static:

/*
 * gcc -c lib.cpp -o lib.obj
 * ar rcs lib.lib lib.obj
 * gcc -c main.cpp -o main.obj
 * gcc -o main main.obj -L. lib.lib
*/


