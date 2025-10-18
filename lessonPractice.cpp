#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class Matrix {
private:
    int size;
    int rows, cols;
    int** data;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocate();
        fillRandom();
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
    void allocate() {
        data = new int* [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }
    void fillRandom() {
        srand(time(0));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = rand() % 100;
    }
    friend ostream& operator<<(ostream& out, const Matrix& other) {
        out << "\ncols : " << other.cols << " rows : " << other.rows << endl;
        for (int i = 0; i < other.rows; i++) {
            for (int j = 0; j < other.cols; j++)
                out << other.data[i][j] << " ";
            out << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Matrix& other) {
        if (other.rows == 0 && other.cols == 0) {
            cout << "Enter number of rows and columns : ";
            in >> other.rows >> other.cols;
            other.allocate();
        }
        cout << "Enter elements of the matrix :\n";
        for (int i = 0; i < other.rows; i++)
            for (int j = 0; j < other.cols; j++)
                in >> other.data[i][j];
        return in;
    }
    void writeToFile(const string& filename) const {
        ofstream fout(filename);
        fout << rows << " " << cols << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                fout << data[i][j] << " ";
            fout << endl;
        }
        fout.close();
    }
    void readFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) return;
        fin >> rows >> cols;
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                fin >> data[i][j];
        fin.close();
    }
};
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int rows, cols;
    cout << "Enter number of rows and cols : " << endl;
    cin >> rows >> cols;
    Matrix m(rows, cols);
    cout << m;
    cin >> m;
    cout << "\nMatrix :\n" << m << endl;
    m.writeToFile("matrix.txt");
    Matrix m2;
    m2.readFromFile("matrix.txt");
    cout << "\nMatrix from file :\n" << m2;

    return 0;
}