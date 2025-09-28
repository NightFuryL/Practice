#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Student {
protected:
    string firstName;
    string lastName;
    string group;
    double averageGrade;

public:
    Student() {}
    Student(string firstName, string lastName, string group, double avgGrade) : firstName(firstName), lastName(lastName), group(group), averageGrade(avgGrade) {
    }

    void showInfo() {
        cout << "First Name : " << firstName << endl;
        cout << "Last Name : " << lastName << endl;
        cout << "Group : " << group << endl;
        cout << "Average Grade : " << averageGrade << endl;
    }
};

class Aspirant : public Student {
private:
    string thesisTopic;
    string text;

public:
    Aspirant() {}

    Aspirant(string firstName, string lastName, string group, double avgGrade, string topic, string text) : Student(firstName, lastName, group, avgGrade), thesisTopic(topic), text(text) {
    }

	void protectionCandidateTheme() {
        //showInfo();
		cout << "-----------------------------------" << endl;
        cout << "Thesis Topic: " << thesisTopic << endl;
		cout << "Aspirant is defending the thesis topic." << endl;
		cout << "-----------------------------------" << endl;
        cout << "\tAspirant : " << firstName << " " << lastName << endl
             << "\tGroup : " << group << endl
             << "\tAverage grade : " << averageGrade << endl
			 << "\tDefending the thesis topic : " << thesisTopic << endl;
		cout << "-----------------------------------" << endl;
		//cout << "bla bla bla..." << endl;
		cout << text << endl;
		cout << "-----------------------------------" << endl;
		cout << "Thesis defense completed." << endl;
		cout << "-----------------------------------" << endl;
    }
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    Aspirant asp("Lev", "Bohlia", "P410", 5, "Space Exploration", "asdfgk;ljihguytdfugihojpk[l");
	asp.showInfo();
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    asp.protectionCandidateTheme();
    return 0;
}
