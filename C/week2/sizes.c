#include <stdio.h>

int main() {

    int s1 = sizeof(int); // 4
    int s2 = sizeof(double); // 8
    int s3 = sizeof(unsigned long long int); // 8
    int s4 = s1 * s2 * s3;

    printf("%d \n %d \n %d \n %d \n", 
            s1, s2, s3, s4);

    return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week2-c-basics/04-sizes
