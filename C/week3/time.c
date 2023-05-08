#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    time_t start = time(NULL);
    sleep(n);
    time_t end = time(NULL);
    double duration = difftime(end, start);
    printf("sleep duration: %.6f seconds\n", duration);

    return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week3-c-pointers-stdlib/07-time
