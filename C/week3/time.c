#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float n;
    n = atoi(argv[1]);
    
    // Add time duration
    sleep(n);
    printf("sleep duration: %f seconds\n", n);

    return 0;
}