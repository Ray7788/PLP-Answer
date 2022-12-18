#include <stdio.h>

typedef enum {
    INT,
    CHAR,
    FLOAT
} array_type;

// writing the "generic" array printing function
void array_print(void *ptr, int size, array_type type) {
    printf("[");

    switch (type){
        case INT:
            for (int i = 0; i < size - 1; i++){
                printf("%d, ", ( (int *) ptr)[i]);
            }
            printf("%d]\n", ((int *) ptr)[size - 1]);
            break;
        case CHAR:
            for (int i = 0; i < size - 1; i++){
                printf("%c, ", ((char *) ptr)[i]);
            }
            printf("%c]\n", ( (char *) ptr)[size - 1]);
            break;
        case FLOAT:
            for (int i = 0; i < size - 1; i++){
                printf("%.6f, ", ((float *) ptr)[i]);
            }
            printf("%.6f]\n", ((float *) ptr)[size - 1]);
            break;
    }
}

int main(int argc, char **argv) {
    int int_tab[3] = {1, 2, 3};
    char char_tab[2] = {'a', 'b'};
    float float_tab[3] = {2.5, 1.1, 12.42};

    array_print(int_tab, 3, INT);
    array_print(char_tab, 2, CHAR);
    array_print(float_tab, 3, FLOAT);

    return 0;
}