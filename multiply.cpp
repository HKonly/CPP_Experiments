#include <stdio.h>

int main() {
    int a = 3322;
    int b = a - a/100*100;

    printf("b is: %d\n", b);
    return 0;
}
