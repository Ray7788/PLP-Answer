#include <stdio.h>
#include <stdlib.h>

// unfinished!!!!
struct timestamp {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

void add_timestamps(struct timestamp *a,  struct timestamp *b,  struct timestamp *c){
    c->hour = a->hour + b->hour;
    c->minute = a->minute + b->minute;
    c->second = c->second + c->second;

    if((c->second) >= 60){
        c->second = c->second %60;
        c->minute++;
    } 

    if((c->minute) >= 60){
        c->minute = c->minute %60;
        c->hour++;
    }
}

int main(int argc, char *argv[]) {
    struct timestamp a,b,c;

    a.hour = atoi(argv[1]);
    a.minute = atoi(argv[2]);
    a.second = (argv[3]);

    b.hour = atoi(argv[4]);
    b.minute = atoi(argv[5]);    
    c.second = atoi(argv[6]);

    add_timestamps(&a, &b, &c);
    printf("%d %d %d",c.hour,c.minute,c.second);

    return 0;
}