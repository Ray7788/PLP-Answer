#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
     int year = atoi(argv[1]); 

     if(year % 4 !=0 ){
         printf("%d is a common year", year);
     }else if(year % 100 != 0){
        printf("%d is a leap year", year);
     }else if(year % 400 != 0){
         printf("%d is a common year", year);
     }else{
        printf("%d is a leap year", year);
     }

     return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week2-c-basics/08-leap
