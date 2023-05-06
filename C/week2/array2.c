#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // argc is an integer variable that stores the number of command-line arguments passed by the user including the name of the program. 
    int array[10];
    int a;

    // At most 10 integers as command line parameters are allowed
    if (argc > 11){
        return -1;
    }
    
    // pay attention to index
    for(int i = 0; i <argc-1; i++){
        array[i] = atoi(argv[i+1]);
    }

    // if each number is even or odd 
    for (int i = 0; i < argc-1; i++){
        if (array[i]%2 ==0){
            printf("%d is even", array[i]);
        }
        if (array[i]%2 ==1){
            printf("%d is odd", array[i]);
        }
    }

}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week2-c-basics/13-array2
