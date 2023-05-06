#include <stdio.h>
#include <stdlib.h>

// It's finished and it works well now!!!!
struct timestamp {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

struct timestamp add_timestamps(struct timestamp a, struct timestamp b){
    // declare a new timestamp that holds the result
    struct timestamp c;
    
    c.hour = a.hour + b.hour;
    c.minute = a.minute + b.minute;
    c.second = a.second + b.second;

    if((c.second) > 59){
        c.minute++;
        c.second -= 60;
    } 

    if((c.minute) > 59){
        c.hour++;
        c.minute -= 60;
    }

    return c;
}

int main(int argc, char **argv) {
    // if command line argument count is not 6, print error and exit program
    if(argc != 7){
        printf("Please provide 6 commandline arguments");
        return -1;
    }

    struct timestamp a,b;

    a.hour = atoi(argv[1]);
    a.minute = atoi(argv[2]);
    a.second = atoi(argv[3]);

    b.hour = atoi(argv[4]);
    b.minute = atoi(argv[5]);    
    b.second = atoi(argv[6]);

    struct timestamp c = add_timestamps(a, b);

    printf("%d %d %d\n",c.hour,c.minute,c.second);

    return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week2-c-basics/11-struct
