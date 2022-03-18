#include <stdio.h>
#include <algorithm>

using namespace std;

int i = 641117;
char c;

int main() {
    printf("Size of i: %ld\tValue of i: %08x\n", sizeof(i), i);
    
    c = i;
    //copy((char*)&i, (char*)&i+2, ac); 
    char ac[2] = {(char)(i>>8), (char)i};
    
    printf("Size of c: %ld\tValue of c: %x\n", sizeof(c), c);

    printf("Size of ac: %ld\tValue of ac: ", sizeof(ac));
    for (int j=0; j<sizeof(ac); j++) {
        printf("%x ", ac[j]);
    }
    printf("\n");

    return 0;
}
