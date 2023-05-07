#include <stdio.h>

int main(int argc, char **argv) {
    char *string = "hello, world!\n";

    char *ptr = string;
    while(*ptr != '\0'){
        printf("%c", *ptr++);
    }

    return 0;
}

// 定义了一个指针变量ptr，并将其初始化为指向字符串string的第一个字符。
// 然后，在while循环中，我们使用指针变量ptr来访问字符串中的字符，并将指针变量ptr递增，以便在下一次迭代中指向下一个字符。
// 最终，当我们遇到字符串的结尾时，即\0字符时，循环停止。