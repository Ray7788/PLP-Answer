#include <iostream>

class Pair {
    private:
        int x;
        int y;

    public: 
        Pair(int x, int y):
            x{x},y{y} {}; 
         
};

int main(int argc, char **argv) {
    Pair p(10,20);

    // p.x = 10;
    // p.y = 20;

	std::cout << "p.x is " << p.x << ", p.y is " << p.y << "\n";

    return 0;
}
