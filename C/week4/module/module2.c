#include <sys/time.h>
#include <stdlib.h>
#include "module2.h"

unsigned long long int module2_function1(void) {
    struct timeval tv;
    unsigned long long res;

    gettimeofday(&tv, NULL);

    res = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return res;
}