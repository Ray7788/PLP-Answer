#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    double a,b,c;

//   注意使用的是atof
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

//     sscanf没有用，只能识别一整个string，不能以空格区分
    //  sscanf(argv[1], "%f %f %f %f", &a);
    //  sscanf(argv[2], "%f", &b);
    //  sscanf(argv[3], "%f", &c);

    double abc = a*b*c;
    printf("%f \n", abc);
 
}
