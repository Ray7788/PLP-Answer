#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this defines a constant MAX_SIZE as 100
#define MAX_SIZE 100

int main(int argc, char *argv[]) {
    char *str1;     
    char *str2;

    printf("input string1:\n");
    // needs memory allocation
    str1 = malloc(MAX_SIZE);
    if (!str1) return -1;
    // read from stdin
    fgets(str1, MAX_SIZE, stdin);

    printf("input string2:\n");
    str2 = malloc(MAX_SIZE); 
    if (!str2) return -1;
    fgets(str2, MAX_SIZE, stdin);

    // strcmp: if same return 0, or return 1  
    if(!strcmp(str1,str2)){
        printf("strings are similar");
    }else{
        printf("strings are different");
    }

    free(str1);
    free(str2);
    return 0;
}


// 由于多个文件（week2也有）都叫string，现特此注明指令，已通过批改
// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week3-c-pointers-stdlib/06-string
