#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
	virtual double GetArea() { return -1; }
};

class Rectangle : public Figure {
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double GetArea() override {
        return width * height;
    }
};

class Circle : public Figure {
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double GetArea() override {
        return 3.14 * radius * radius;
    }
};

class Triangle : public Figure {
    double base, height;
public:
    Triangle(double base, double height) : base(base), height(height) {}
    double GetArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Figure* fig = nullptr;
    int choice;
    double a, b;

    cout << "Menu : " << endl;
    cout << "1 - Rectangle" << endl;
    cout << "2 - Circle" << endl;
    cout << "3 - Triangle" << endl;
    cout << "Your choice : " << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter width : ";
        cin >> a;
        cout << "Enter height : ";
        cin >> b;
        fig = new Rectangle(a, b);
    }
    else if (choice == 2) {
        cout << "Enter radius : ";
        cin >> a;
        fig = new Circle(a);
    }
    else if (choice == 3) {
        cout << "Enter base : ";
        cin >> a;
        cout << "Enter height : ";
        cin >> b;
        fig = new Triangle(a, b);
    }
    else {
        cout << "Invalid choice" << endl;
        return 0;
    }

    cout << "Area : " << fig->GetArea() << endl;

    delete fig;
    return 0;
}
