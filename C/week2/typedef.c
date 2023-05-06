#include <stdio.h>
#include <stdlib.h>

// this line typedef's 'unsigned long long int' to 'ull'
typedef unsigned long long int ull;

struct s_rectangle {
    ull width;
    ull length;
};

// this line typedef's 'struct s_rectangle' to 'rectangle'
typedef struct s_rectangle rectangle;

void print_rectangle(rectangle r) {
    printf("Rectangle is %llu x %llu\n", r.width, r.length);
}

int main(int argc, char **argv) {
    rectangle r;
    ull width;
    ull length;

    if(argc == 3) {
        width = atoll(argv[1]);
        length = atoll(argv[2]);

        r.width = width;
        r.length = length;

        print_rectangle(r);
    }

    return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week2-c-basics/10-typedef
