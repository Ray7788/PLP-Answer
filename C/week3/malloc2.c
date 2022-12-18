#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    // initialize 2d array
    int **array;

    // check that only two commandline arguments are passed(2 for argument and 1 for program name)
    if (argc != 2+1) return -1;

    // store each argument in variables
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    array = malloc( row * sizeof(int *));
    // exit program if malloc failed
    if (!array) return -1;

    for (int i = 0; i < row; ++i){
        array[i] = malloc(col * sizeof(int *));
        if (!array[i]) return -1;
    }

    // a variable that counts from 0 to row * col - 1
    int incrementor = 0;

    // allocate the numbers 0 to x * y - 1 in 2d array, in order
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            array[i][j] = incrementor;
            incrementor++;
        }
    }

    // print elements in array, each 1d array taking one line
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("%d ", array[i][j]);
        }
        // at the end of each line return new line
        printf("\n");
    }

    // free the allocated memory for each of the 1d arrays
    // we do this before deallocating memory for 2d array because we can't access the 1d arrays once we free the 2d array
    for (int i =0; i < row; ++i){
        free(array[i]);
    }

    // free the allocated memory for 2d array
    free(array);

    return 0;
}