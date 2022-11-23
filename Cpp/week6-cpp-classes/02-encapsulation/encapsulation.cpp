#include <iostream>

class Rectangle {
private:
    float length;
    float width;
public:
    Rectangle(float len, float wid){
        length = len;
        width = wid;  
        // std::cout << "Constructor call\n";
    }
    float rectangle_perimeter(void);

    float get_length(void){
        return length;
    }

    float get_width(void){
        return width;
    }
};   

class Circle {
private:
    float radius;
public:
    Circle(float rad){
        radius = rad;
    }
    float circle_circumference(void);
    
    float get_radius(void){
        return radius;
    }
};

float Rectangle::rectangle_perimeter() {
    return 2.0 * (length + width);
}

float Circle::circle_circumference() {
    return 2.0 * 3.14 * radius;
}

int main(int argc, char **argv) {
    Rectangle r(10,20);
    Circle c(1);

    // r.length = 10;
    // r.width = 20;

    // c.radius = 1;

	std::cout << "Rectangle l: " << r.get_length() << ", w: " << r.get_width();
	std::cout << ", perimeter: " << r.rectangle_perimeter() << "\n";

	std::cout << "Circle r: " << c.get_radius();
	std::cout << ", circumference: " << c.circle_circumference() << "\n";
    return 0;
}
