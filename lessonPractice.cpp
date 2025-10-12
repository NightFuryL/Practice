#include <iostream>
#include <Windows.h>

using namespace std;

int toInt(double i) {
    return static_cast<int>(i);
}
class Shape {
public:
    virtual double getPerimeter() const = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double getPerimeter() const override { return 2 * 3.14 * radius; }
};
char* voidToChar(void* ptr) {
    return static_cast<char*>(ptr);
}
class Vehicle {
public:
    virtual ~Vehicle() {}
};
class Car : public Vehicle {};
class Bicycle : public Vehicle {};
void checkTypeVehicle(Vehicle* vehicle) {
    if (typeid(*vehicle) == typeid(Car)) cout << "Car\n";
    else if (typeid(*vehicle) == typeid(Bicycle)) cout << "Bicycle\n";
}

void castVehicle(Vehicle& vehicle) {
    try {
        Car& car = dynamic_cast<Car&>(vehicle);
        cout << "Good\n";
    }
    catch (bad_cast&) {
        cout << "Error\n";
    }
}
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    cout << toInt(5.7) << endl;

    Circle c(3);
    Shape* s = static_cast<Shape*>(&c);
    Circle* c2 = static_cast<Circle*>(s);
    cout << c2->getPerimeter() << endl;
    char text[] = "ItStep";
    void* ptr = text;
    cout << voidToChar(ptr) << endl;
    Vehicle* arr[] = { new Car(), new Bicycle(), new Car() };
    for (auto v : arr) checkTypeVehicle(v);
    Car car;
    Bicycle b;
    castVehicle(car);
    castVehicle(b);
    for (auto v : arr) delete v;
}