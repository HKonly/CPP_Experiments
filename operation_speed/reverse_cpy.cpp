#include <iostream>
#include <cstring>
#include <algorithm>
#include <typeinfo>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    unsigned char testarr[3735552];
    unsigned char copied[3735552];
    for(int i=0 ; i < sizeof(testarr) ; i++) {
        testarr[i] = i % 4;
    }

    system_clock::time_point start;
    system_clock::time_point end;

    printf("[Test with %lu size of unsigned char (1-byte) array]\n", sizeof(testarr));
    // memcpy
    printf("Testing regular memcpy\n");

    start = system_clock::now();
    memcpy(copied, testarr, sizeof(testarr));
    end = system_clock::now();
    nanoseconds elapsed = end - start;

    printf("The time elapsed (nanosec): %ld\n\n", elapsed.count());

    // copy
    printf("Testing STL copy\n");

    start = system_clock::now();
    copy(testarr, testarr+sizeof(testarr), copied);
    end = system_clock::now();
    elapsed = end - start;
    
    printf("The time elapsed (nanosec): %ld\n\n", elapsed.count());

    // reverse copy
    printf("Testing reverse copy\n");

    start = system_clock::now();
    reverse_copy(testarr, testarr+sizeof(testarr), copied);
    end = system_clock::now();
    elapsed = end - start;

    printf("The time elapsed (nanosec): %ld\n\n", elapsed.count());
}
