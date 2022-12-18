#include <iostream>
#include <stdio.h>

class Pair {
public: 
    int x;
    int y;
    // 这是构造函数
    Pair(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int main(int argc, char **argv) {
    Pair p(10, 20);
	std::cout << "p.x is " << p.x << ", p.y is " << p.y << "\n";

    return 0;
}
