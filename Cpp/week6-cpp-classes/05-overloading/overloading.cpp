#include <iostream>

class Complex {
private:
    int real{0};
    int imag{0};

public:
    Complex() = default;
    Complex(int real_part, int imaginary_part);
    int get_real_part();
    int get_imaginary_part();
};

Complex::Complex(int real_part, int imaginary_part) 
    : real{real_part}, imag{imaginary_part} {};

int Complex::get_real_part() {
    return real;
}

int Complex::get_imaginary_part() {
    return imag;
}

/* implement add_and_print here */
void add_and_print(Complex c1, Complex c2){
    int r1 = c1.get_real_part();
    int im1 = c1.get_imaginary_part();
    int r2 = c2.get_real_part();
    int im2 = c2.get_imaginary_part();
    int rTotal = r1 + r2;
    int imTotal = im1 + im2;
    // Complex(rTotal,imTotal);
    std::cout << "(" << r1 << "+" << im1 << "i" << ")" << " + " << "(" << r2 << "+" << im2 << "i" << ")" << " = " << "(" << rTotal << "+" << imTotal << "i" << ")" << "\n";
}

void add_and_print(double d1, double d2){
    int res = d1 + d2;
    std::cout << d1 << " + " << d2 << " = " << res << "\n";
}

void add_and_print(int i1, int i2){
    int res = i1 + i2;
    std::cout << 11 << " + " << i2 << " = " << res << "\n";

}

int main(int argc, char **argv) {
    Complex c1(4, 5);
    Complex c2(9, 11);
    int i1 = 4, i2 = 9;
    double d1 = 5.8, d2 = 11.2;

    add_and_print(c1, c2); // should print "(4+5i) + (9+11i) = (13+16i)"
    add_and_print(i1, i2); // should print "4 + 9 = 13"
    add_and_print(d1, d2); // should print "5.800000 + 11.200000 = 17.000000"

    return 0;
}
