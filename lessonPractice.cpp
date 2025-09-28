#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
//============================================
//3
class Circle {
protected:
    double radius;
    double lengthCircle;
public:
    Circle(double radius) : radius(radius) {}
    double getArea() {
        return 3.14 * radius * radius;
    }
    double getLengthCircle() {
        return 2.0 * 3.14 * radius;
    }
    void showCircle() {
        cout << "Circle radius : " << radius << endl;
        cout << "Circle area : " << getArea() << endl;
        cout << "Circle length : " << getLengthCircle() << endl;
    }
};
class Square {
protected:
    double side;
public:
    Square(double side) : side(side) {}
    double getArea() {
        return side * side;
    }
    void showSquare() {
        cout << "Square side : " << side << endl;
        cout << "Square area : " << getArea() << endl;
    }
};
class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double side) : Square(side), Circle(side / 2) {}

    void showInfo() {
        cout << "Circle in Square" << endl;
        showSquare();
        showCircle();
    }
};
// ============================================
// 4
class Wheels {
protected:
    int wheelCount;
public:
    Wheels(int count) : wheelCount(count) {}

    void showWheels() {
        cout << "Number of wheels: " << wheelCount << endl;
    }
};
class Engine {
protected:
    int horsepower;
public:
    Engine(int horsepower) : horsepower(horsepower) {}
    void showEngine() {
        cout << "Engine horsepower : " << horsepower << " HP" << endl;
    }
};
class Doors {
protected:
    int doorCount;
public:
    Doors(int count) : doorCount(count) {}
    void showDoors() {
        cout << "Number of doors : " << doorCount << endl;
    }
};
class Seats {
protected:
    int seatCount;
public:
    Seats(int count) : seatCount(count) {}
    void showSeats() {
        cout << "Number of seats : " << seatCount << endl;
    }
};
class Windows {
protected:
    int windowCount;
public:
    Windows(int count) : windowCount(count) {}
    void showWindows() {
        cout << "Number of windows : " << windowCount << endl;
    }
};
class Lights {
protected:
    int lightCount;
public:
    Lights(int count) : lightCount(count) {}
    void showLights() {
        cout << "Number of lights : " << lightCount << endl;
    }
};
class FuelTank {
protected:
    double capacity;
public:
    FuelTank(double cap) : capacity(cap) {}
    void showFuelTank() {
        cout << "Fuel tank capacity : " << capacity << " liters" << endl;
    }
};
class Transmission {
protected:
    string type;
public:
    Transmission(string t = "Manual") : type(t) {}
    void showTransmission() {
        cout << "Transmission type : " << type << endl;
    }
};
class Car : public Wheels, public Engine, public Doors, public Seats,
    public Windows, public Lights, public FuelTank, public Transmission {
private:
    string brand;
public:
    Car(string brand, int Wheels, int horsepower, int doors, int Seats,
        int Windows, int lights, double tank, string Transmission)
        : brand(brand),
        Wheels(Wheels), Engine(horsepower), Doors(doors), Seats(Seats),
        Windows(Windows), Lights(lights), FuelTank(tank), Transmission(Transmission) {
    }
    void showCar() {
        cout << "--- Car Information ---" << endl;
        cout << "Brand : " << brand << endl;
        showWheels();
        showEngine();
        showDoors();
        showSeats();
        showWindows();
        showLights();
        showFuelTank();
        showTransmission();
    }
};
//============================================
int main() {
        //3
        CircleInSquare cis(10);
    cis.showInfo();
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    //4
    Car car("Koenigsegg", 1, 111, 1, 1, 1, 1, 11.1, "Automatic");
    car.showCar();

    return 0;
}
