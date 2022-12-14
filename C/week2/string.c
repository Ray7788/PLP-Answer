#include <stdio.h>

int main(int argc, char **argv) {
    char string[9];

    string[0] = 'h';
    string[1] = 'i';
    string[2] = ' ';
    string[3] = 't';
    string[4] = 'h';
    string[5] = 'e';
    string[6] = 'r';
    string[7] = 'e';
    string[8] = '\0';   // Add '\0' as termination character

    printf("%s\n", string);

    return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week2-c-basics/06-string
