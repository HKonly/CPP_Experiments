#include <stdio.h>
#include <chrono>
#include <time.h>

int main(void) {
    time_t current = time(NULL);
    std::tm* tm = localtime(&current);
    
    printf("tm_year: %d\n", tm->tm_year);
    printf("tm_mon: %d\n", tm->tm_mon);
    printf("tm_mday: %d\n", tm->tm_mday);
    printf("tm_hour: %d\n", tm->tm_hour); 
    return 0;
}
