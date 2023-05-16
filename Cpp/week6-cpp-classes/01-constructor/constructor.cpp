#include <iostream>
#include <stdio.h>

class Pair {
public: 
    int x;
    int y;
    // 这是构造函数 C++新版写法
    Pair(int x, int y): x(x), y(y){
        // this->x = x;
        // this->y = y;
    }
};

int main(int argc, char **argv) {
    // 封装数据
    Pair p(10, 20);
	std::cout << "p.x is " << p.x << ", p.y is " << p.y << "\n";

    return 0;
}
