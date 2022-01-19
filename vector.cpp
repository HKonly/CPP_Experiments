#include <stdio.h>
#include <vector>
#include <cstring>
#include <stdint.h>
#include <time.h>

using namespace std;

int main(void) {
    vector<uint8_t> vec;

    printf("Pushing start\n");
    for (int i=0; i<3535556; i++) {
        vec.push_back(0xED);
    }
    printf("Pushing ends\n\n");

    char test_loop[3535556];
    int i = 0;

    clock_t start = clock();
    for(const uint8_t &item: vec) {
        test_loop[i++] = item;
    }
    clock_t end = clock();
    int result = (int) (end - start);

    printf("Execution time: %d\n", result);

    
    char test_memcpy[3535556];

    start = clock();
    memcpy(test_memcpy, &vec[0], 3535556);
    end = clock();

    result = (int) (end - start);
    printf("Execution time: %d\n", result);
}
