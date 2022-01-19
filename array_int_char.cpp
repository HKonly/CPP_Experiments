#include <stdio.h>

int main() {
    int a[] = {100, 200};
    unsigned char* c = (unsigned char*)&a;

    printf("Value of a in hex\t:");
    for (int i=0 ; i<(sizeof(a)/sizeof(a[0])) ; i++) {
        printf(" %08x", a[i]);
    }
    printf("\n");

    printf("Value of c in hex\t:");
    for (int i=0 ; i<(sizeof(c)/sizeof(c[0])) ; i++) {
        printf(" %02x", c[i]);
    }
    printf("\n");
    printf("%p\n", c);
    printf("%p\n", &a);
    
    return 0;
}
