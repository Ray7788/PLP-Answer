#include <stdio.h>

// new enum - each item represents a number from 0~6
enum day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(int argc, char **argv) {
    // use enum
    enum day d = WEDNESDAY;

    printf("Today is: ");
    switch(d) {
        // similarly to above, we convert each integer value with matching enum values
        case MONDAY:
            printf("Monday\n");
            break;
        case TUESDAY:
            printf("Tuesday\n");
            break;
        case WEDNESDAY:
            printf("Wednesday\n");
            break;
        case THURSDAY:
            printf("Thursday\n");
            break;
        case FRIDAY:
            printf("Friday\n");
            break;
        case SATURDAY:
            printf("Saturday\n");
            break;
        case SUNDAY:
            printf("Sunday\n");
            break;

        default:
            printf("Unknown day...\n");
    }
    return 0;
}