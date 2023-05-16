#include <iostream>

class Pair {
private:
    int x;
    int y;
public:
    Pair(int x, int y);
    ~Pair();
    void print();
};

Pair::Pair(int x, int y){
    this->x = x;
    this->y = y;
}

// destructor
Pair::~Pair(){
// empty
}
    
void Pair::print() {
    std::cout << "Pair x: " << x << ", y: " << y << "\n";
}


class TopLevel {
private:
    Pair *p;
    int val;
public:
    TopLevel(int x, int y, int val);
    ~TopLevel();
    void print();
};

TopLevel::TopLevel(int x, int y, int val) {
    // {new Pair(x, y)}, val{val} {}

    p = new Pair(x,y);
    this->val = val;
}

// destructor
TopLevel::~TopLevel(){
    delete p;
}

void TopLevel::print() {
    std::cout << "Toplevel val: " << val << ", with pair:\n";
    p->print();
}


int main(int argc, char **argv) {
    TopLevel t(10, 20, 30);
    t.print();
    return 0;
}
