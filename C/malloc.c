#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *array = malloc(sizeof(int) * (argc-1));
    int a;

//   由command line存入指定的数组array,注意初始下标
    for(int i = 0; i <argc-1; i++){
        array[i] = atoi(argv[i+1]);
    }

//   按照升序排序 ascending order
    for (int i = 0; i < argc-1; i++){
        for (int j = i + 1; j < argc-1; j++){
            if (array[i] > array[j]){
                a = array[i];
                    array[i] = array[j];
                    array[j] = a;
            }
        }
    }

//   打印输出print
    for (int j = 0; j < argc-1; j++ ){
        printf("%d ", array[j]);
    }

    free(array);
    return 0;
}
