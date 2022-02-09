#include <stdio.h>
#include <time.h>
#include <cstring>

using namespace std;

int main(void) {
    char sptest[12];
    char test[12] = "can01010101";
    time_t tt = time(NULL);
    tm now;
    localtime_r(&tt, &now);

    int test_count = 100000;
    int sprintf_time = 0;
    int char_assign_time = 0;

    for (int idx=0 ; idx < test_count ; idx++) {

        clock_t start = clock();
        sprintf(sptest, "can%02d%02d%02d%02d", (now.tm_year-100), (now.tm_mon), (now.tm_mday), (now.tm_hour));
        clock_t end = clock();
        sprintf_time += (end-start);
//        printf("diff: %ld\n\n", end-start);
    
        start = clock();
        test[0] = 'c'; test[1] = 'a'; test[2] = 'n';
        long year = now.tm_year-100;	test[3] = year/10+'0'; test[4] = year%10+'0'; 
        long mon = now.tm_mon;		test[5] = mon/10+'0'; test[6] = mon%10+'0';
        long day = now.tm_mday;		test[7] = day/10+'0'; test[8] = day%10+'0';
        long hour = now.tm_hour;	test[9] = hour/10+'0'; test[10] = hour%10+'0';
        end = clock();
        char_assign_time += (end-start);
//        printf("diff: %ld\n\n", end-start);
//        printf("string from sprintf:\t%s\n", sptest);
//        printf("string from chararr:\t%s\n", test);
    }
    printf("sprintf_mean \t\t%4.2f ms\n", (float)sprintf_time/(float)test_count);
    printf("char_assign_mean \t%4.2f ms\n", (float)char_assign_time/(float)test_count);

    return 0;
}
