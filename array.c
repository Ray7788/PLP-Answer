#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int array[argc-1];
    int a;

//   由command line存入指定的数组array
    for(int i = 1; i <argc-1; i++){
        array[i-1] = atoi(argv[i]);
    }

//   按照升序排序
    for (int i = 0; i < argc-1; i++){
        for (int j = i + 1; j < argc-1; j++){
            if (array[i] > array[j]){
                a = array[i];
                array[i] = array[j];
                array[j] = a;
            }
        }
    }

  打印输出
    for (int j = 0; j < argc-1; j++ ){
        printf("%d ", array[j]);
    }

}
