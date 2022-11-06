#include <stdio.h>

int main() {

    int s1 = sizeof(int);
    int s2 = sizeof(double);
    int s3 = sizeof(unsigned long long int);
    int s4 = s1 * s2 * s3;

    printf("%d \n %d \n %d \n %d \n", 
            s1, s2, s3, s4);

    return 0;
}
