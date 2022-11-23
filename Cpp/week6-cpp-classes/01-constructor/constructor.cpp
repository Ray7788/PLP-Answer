#include <iostream>

class Pair {
    private:
        int x;
        int y;

    public: 
        Pair(){
          x = 10;
          y = 20;
        }

    		void getValueA()                 //成员函数（打印成员变量值）
        {
          std::cout<<a;
        };

        void getValueB()                 //成员函数（打印成员变量值）
        {
          std::cout<<b;
        };

int main(int argc, char **argv) {
    Pair p;

    // p.x = 10;
    // p.y = 20;

	std::cout << "p.x is " << p.getvalueA << ", p.y is " << p.getvalueB << "\n";

    return 0;
}
