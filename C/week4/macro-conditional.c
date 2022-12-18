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

    #ifdef DEBUGMODE
    printf("[DEBUG] Generated %d random numbers\n", size);
    #endif
}

int main(int argc, char **argv) {
    // initialize 5 bins
    int bins[5] = {0, 0, 0, 0, 0};
// -------------------------------------------------------------------------------
    #ifdef DEBUGMODE
    printf("[DEBUG] Allocating memory\n");
    #endif

    // initialize 1d array
    int *array = malloc(SAMPLE_SIZE * sizeof(int *));
// -------------------------------------------------------------------------------
    if(!array) {return -1;}

    #ifdef DEBUGMODE
    printf("[DEBUG] Allocation successfull\n");
// -------------------------------------------------------------------------------
    printf("[DEBUG] Filling array\n");
    #endif
    
    fill_array(array, SAMPLE_SIZE);
// -------------------------------------------------------------------------------
    #ifdef DEBUGMODE
    printf("[DEBUG] Dividing numbers into bins\n");
    #endif

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
// -------------------------------------------------------------------------------
    #ifdef DEBUGMODE
    printf("[DEBUG] Printing results\n");
    #endif

    for(int i=0; i<5; i++) {
        printf("bin %d: [%03d - %03d[ ",    i, (MAX_VAL/5)*i, (MAX_VAL/5)*(i+1));

        for(int j=0; j<(bins[i]*MAX_VAL) / SAMPLE_SIZE; j++){
            printf("*");    // print stars
        }
        printf("\n");
    }
    
    #ifdef DEBUGMODE
    printf("[DEBUG] Printing done\n");
    #endif
// -------------------------------------------------------------------------------
    free(array);

    #ifdef DEBUGMODE
    printf("[DEBUG] Memory freed\n");
    #endif
// -------------------------------------------------------------------------------

    return 0;
}
