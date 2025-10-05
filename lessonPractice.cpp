#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& fout) const = 0;
    virtual void Load(ifstream& fin) = 0;
    virtual ~Shape() {}
};
class Square : public Shape {
    double side;
public:
    Square(double side = 0) : side(side ) {}

    void Show() const override {
        cout << "Square, side = " << side << endl;
    }

    void Save(ofstream& fout) const override {
        fout << "Square " << side << endl;
    }

    void Load(ifstream& fin) override {
        fin >> side;
    }
};

class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double a = 0, double b = 0) : a(a), b(b) {}

    void Show() const override {
        cout << "Rectangle, a = " << a << ", b = " << b << endl;
    }

    void Save(ofstream& fout) const override {
        fout << "Rectangle " << a << " " << b << endl;
    }

    void Load(ifstream& fin) override {
        fin >> a >> b;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double radius = 0) : radius(radius) {}

    void Show() const override {
        cout << "Circle, radius = " << radius << endl;
    }

    void Save(ofstream& fout) const override {
        fout << "Circle " << radius << endl;
    }

    void Load(ifstream& fin) override {
        fin >> radius;
    }
};
int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Square(5));
    shapes.push_back(new Rectangle(3, 7));
    shapes.push_back(new Circle(4));
    ofstream fout("shapes.txt");
    for (auto s : shapes) {
        s->Save(fout);
    }
    fout.close();
    for (auto s : shapes) delete s;
    shapes.clear();
    ifstream fin("shapes.txt");
    string type;
    while (fin >> type) {
        Shape* s = nullptr;
        if (type == "Square") s = new Square();
        else if (type == "Rectangle") s = new Rectangle();
        else if (type == "Circle") s = new Circle();

        if (s) {
            s->Load(fin);
            shapes.push_back(s);
        }
    }
    fin.close();
    cout << "\nShapes loaded from file : \n";
    for (auto s : shapes) {
        s->Show();
    }
    for (auto s : shapes) delete s;
    return 0;
}
