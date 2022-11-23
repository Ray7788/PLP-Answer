#include <iostream>

class Pair {
private:
    int x;
    int y;

public: 
    Pair(int x, int y);
    
    // void getValueA()                 //成员函数（打印成员变量值）
    // {
    //   std::cout<<a;
    // };

    // void getValueB()                 //成员函数（打印成员变量值）
    // {
    //   std::cout<<b;
    // };
}

Pair::Pair(int x, int y) :
x{x}, y{y} {}

int main(int argc, char **argv) {
    Pair p;

    // p.x = 10;
    // p.y = 20;

	std::cout << "p.x is " << p.getvalueA << ", p.y is " << p.getvalueB << "\n";

    return 0;
}
