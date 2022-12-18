#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_SIZE 10
#define MAX_VAL 50

// auto-generated 0 and 99 
void fill_array(int *ptr, int size) {
    srand(time(NULL));
    for(int i = 0; i<size; i++)
        ptr[i] = rand() % 100;
}

int main(int argc, char **argv) {
    // initialize 5 bins
    int bins[5] = {0, 0, 0, 0, 0};
    // initialize 1d array
    int *array = malloc(SAMPLE_SIZE * sizeof(int *));
    if(!array) {return -1;}

    fill_array(array, SAMPLE_SIZE);

    for(int i=0; i<SAMPLE_SIZE; i++) {
        int n = array[i];

        if(n < MAX_VAL/5)
            bins[0]++;
        else if(n >= MAX_VAL/5 && n < (MAX_VAL/5)*2)
            bins[1]++;
        else if(n >= (MAX_VAL/5)*2 && n < (MAX_VAL/5)*3)
            bins[2]++;
        else if(n >= (MAX_VAL/5)*3 && n < (MAX_VAL/5)*4)
            bins[3]++;
        else
            bins[4]++;
    }


    for(int i=0; i<5; i++) {
        printf("bin %d: [%03d - %03d[ ",    i, (MAX_VAL/5)*i, (MAX_VAL/5)*(i+1));

        for(int j=0; j<(bins[i]*MAX_VAL) / SAMPLE_SIZE; j++){
            printf("*");    // print stars
        }
        printf("\n");
    }

    free(array);
    return 0;
}
