#include <stdio.h>

int main(int argc, char *argv[]) {
    int num;
    sscanf(argv[1], "%d", &num);

    // Pointer can be printed in hexadecimal and prefixed with 0x using the %p format specifier for printf.
    printf("Variable contains %d and is located @%p\n", num, (void*)&num);

    return 0;
}

// void*是一种通用的指针类型，它可以指向任何类型的数据。
// 使用(void*)是将&var的类型从int*强制转换为void*类型，这样做的目的是为了将指针变量&var的值以void*的形式传递给printf函数。