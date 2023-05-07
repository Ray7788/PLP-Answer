#include <stdio.h>
#include <stdlib.h>


int main(){
    // (int *)强制转换
    int *arr = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    for (int j = 0; j < 10; j++)
    {
        printf("%d\n", arr[j]);
    }
    
    free(arr);
    return 0;

}