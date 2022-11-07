#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str1[20];     char str2[20];
    printf( "input string1:");
    fgets(str1, 15, stdin);
    printf( "input string1:");
    fgets(str2, 15, stdin);

    if(strcmp(str1,str2) == 0){
        printf("strings are similar");
    }else{
        printf("strings are different");
    }

    return 0;
}