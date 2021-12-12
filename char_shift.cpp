#include <stdio.h>
#include <cstring>
#include <cmath>

int main() {
    char testChar, testChar2, testChar3, testChar4;
    int a = 1000;

    testChar = (char) a;
    testChar2 = (char) (a>>8);
    testChar3 = (char) (a>>16);
    testChar4 = (char) (a>>24);

    printf("%08x, ", a);
    printf("%08x, ", a>>8);
    printf("%02x, ", testChar);
    printf("%02x, ", testChar2);
    printf("%02x, ", testChar3);
    printf("%02x\n", testChar4);

    char* testStr = "This is testStr";
    char testChar5 = testStr[0];
    printf("%c", testChar5);

    return 0;
}
