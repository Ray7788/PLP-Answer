#include <iostream>

// 使用类模板<T>，进行整体替换
// 但是批改脚本识别不到使用了类模板，虽然输出结果是对的
template <class T>
class Complex {
private:
    T real{0};
    T imag{0};

public:
    Complex() = default;
    Complex(T real_part, T imaginary_part);
    T get_real_part();
    T get_imaginary_part();
    
    Complex operator+(Complex& other);
};

template <class T>
Complex<T>::Complex(T real_part, T imaginary_part) 
    : real{real_part}, imag{imaginary_part} {};

template <class T>
T Complex<T>::get_real_part() {
    return real;
}

template <class T>
T Complex<T>::get_imaginary_part() {
    return imag;
}

template <class T>
Complex<T> Complex<T>::operator+(Complex<T>& other) {
    return Complex(real + other.real, imag + other.imag);
}

template <class T>
std::ostream& operator<<(std::ostream& out, Complex<T> c) {
    return std::cout << "(" << c.get_real_part() << "+" << c.get_imaginary_part() << "i)";
}

template <typename T>
void add_and_print(T t1, T t2) {
    std::cout << t1 << " + " << t2 << " = " << t1 + t2 << "\n";
}

int main(int argc, char **argv) {
    Complex c1(4, 5);
    Complex c2(9, 11);
    Complex c3(4.1, 5.1);
    Complex c4(8.9, 10.9);

    add_and_print(c1, c2); // should print "(4+5i) + (9+11i) = (13+16i)"
    add_and_print(c3, c4); // should print "(4.1+5.1i) + (8.9+10.9i) = (13+16i)"

    return 0;
}
