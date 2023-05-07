#include <stdio.h>

/* Typedef struct forward declaration for the pointer member */
// typedef struct 结构体名称 结构体变量名
typedef struct s_list_member list_member;

typedef struct s_list_member {
    int value;
    list_member *next;  // a pointer pointing towards next "s_list_member"
} list_member;  //  list_member 在struct结尾声明，就不用在main声明了

int main(int argc, char **argv) {
    list_member lm1, lm2, lm3;

    lm1.value = 1; lm1.next = &lm2;
    lm2.value = 2; lm2.next = &lm3;
    lm3.value = 3; lm3.next = 0x0;  // end of linkedlist

    // lm1.next = lm2 | lm2.next = lm3 | lm3->value = 3
    printf("third member value is: %d\n", lm1.next->next->value);

    return 0;
}

// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week3-c-pointers-stdlib/02-pointer2
