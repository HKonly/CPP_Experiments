#include <stdio.h>

int main() {
    FILE* fp = 0;
    fp = fopen("test.txt", "wt");

    int a = 30;

    // write file
    fprintf(fp, "%04d", a);

    if (fp != 0) {
        fclose(fp);
    }

    return 0;
}
