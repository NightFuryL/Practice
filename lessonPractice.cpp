#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

/*struct Time {
private:
    string name;
public:
    Time(string name) : name(name){}
    
};*/

struct Train {
    string number;
    string time;
    string destination;
};

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Train> trains;
    int choice;
    do {
        cout << "\n1 - Add train\n2 - Show all trains\n3 - Find Train\n0 - Exit\nYour choice : ";
        cin >> choice;
        if (choice == 1) {
            Train t;
            cout << "Number of train : ";
            cin >> t.number;
            cout << "Departure time : ";
            cin >> t.time;
            cout << "Station of destination : ";
            cin.ignore();
            getline(cin, t.destination);
            trains.push_back(t);
        }
        else if (choice == 2) {
            for (auto& t : trains)
                cout << "Train " << t.number << " | " << t.time << " | " << t.destination << endl;
        }
        else if (choice == 3) {
            string num;
            cout << "Enter the number of train : ";
            cin >> num;
            bool found = false;
            for (auto& t : trains)
                if (t.number == num) {
                    cout << "Train " << t.number << " | " << t.time << " | " << t.destination << endl;
                    found = true;
                }
            if (!found) cout << "Train didnt find\n";
        }
    } while (choice != 0);
    return 0;
}