#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

class Passport {
protected:
    string firstName;
    string lastName;
    string nationality;
    string dateOfBirth;
    string passportNumber;
    string expiryDate;
    string sex;//Стать !

public:
    Passport() {}

    Passport(string firstName, string lastName, string nation, string dateOfBirth, string passportNumber, string expiryDate, string sex) : firstName(firstName), lastName(lastName), nationality(nation), dateOfBirth(dateOfBirth), passportNumber(passportNumber), expiryDate(expiryDate), sex(sex) {
    }
    void showInfo() {
        cout << "First Name : " << firstName << endl;
        cout << "Last Name : " << lastName << endl;
        cout << "Nationality : " << nationality << endl;
        cout << "Date of Birth : " << dateOfBirth << endl;
        cout << "Passport Number : " << passportNumber << endl;
        cout << "Expiry Date : " << expiryDate << endl;
        cout << "Sex : " << sex << endl;
    }

};

class ForeignPassport : public Passport {
private:
    string foreignPassNumber;
	string foreignExpiryDate;
    vector<string> visas;

public:
    ForeignPassport() {}

    ForeignPassport(string firstName, string lastName, string nation, string dateOfBirth,string passportNumber, string expiryDateDefaultPassport,string foreignNum,string foreignExpiryDate,string sex) : Passport(firstName, lastName, nation, dateOfBirth, passportNumber, expiryDateDefaultPassport, sex), foreignPassNumber(foreignNum), foreignExpiryDate(foreignExpiryDate) {
    }

    void addVisa(const string& visa) {
        visas.push_back(visa);
    }

    void showForeignInfo() {
        showInfo();
        cout << "Foreign Passport Number : " << foreignPassNumber << endl;
		cout << "Foreign Passport Expiry Date : " << foreignExpiryDate << endl;
        cout << "Visas: ";
        if (visas.empty()) cout << "None" << endl;
        else {
            cout << endl;
            for (int i = 0; i < visas.size(); ++i) {
                cout << i <<  " - " << visas[i] << endl;
            }
        }
    }
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    ForeignPassport fp("Лев", "Богля", "Україна", "11.11.1111", "UA123456789", "22.22.2222", "FOREIGN123456789", "30.30.3030", "Male");
    fp.addVisa("USA");
    fp.addVisa("Canada");
    fp.showForeignInfo();

    return 0;
}
