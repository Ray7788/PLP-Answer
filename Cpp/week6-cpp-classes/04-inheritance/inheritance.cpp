#include <iostream>

/* Class definition and member function implementation here */
class Vehicle
{
private:
    int mileage;

public:
    Vehicle(int mileage){
        this->mileage = mileage;
    }

    ~Vehicle(){

    }
    int get_mileage();
};

int Vehicle::get_mileage(){
    return mileage;
}

////////////////////////////////////////////////////////

class Car : public Vehicle
{
private:
    int steering_wheels;
public:
    Car(int mileage, int steering_wheels):Vehicle(mileage){
        // this->mileage = mileage;
        this->steering_wheels = steering_wheels;
    }

    // ~Car:public Vehicle();
    ~Car(){}
    int get_steering_wheels();
};

int Car::get_steering_wheels(){
    return steering_wheels;
}

//////////////////////////////

class Motorbike : public Vehicle
{
private:
    int cc_class;
public:
    Motorbike(int mileage, int cc_class):Vehicle(mileage){
        this->cc_class = cc_class;
    }

    ~Motorbike(){}
    int get_cc_class();
};

int Motorbike::get_cc_class(){
    return cc_class;
}


int main(int argc, char **argv) {
    Vehicle v(20000);  // a Vehicle with mileage = 20000 miles
    Car c1(10000, 2);  // a Car with mileage = 10000 miles and 2 steering wheels
    Car c2(5000, 4);   // a Car with mileage = 5000 miles and 4 steering wheels
    Motorbike m(50000, 500); // a Motorbike with mileage = 50000 miles and class 500cc

    std::cout << "v's mileage is: " << v.get_mileage() << "\n";
    
    std::cout << "c1's mileage is: " << c1.get_mileage();
    std::cout << ", steering wheels: " << c1.get_steering_wheels() << "\n";

    std::cout << "c2's mileage is: " << c2.get_mileage();
    std::cout << ", steering wheels: " << c2.get_steering_wheels() << "\n";
    
    std::cout << "m's mileage is:  " << m.get_mileage();
    std::cout << ", cc class: " << m.get_cc_class() << "\n";

    return 0;
}
