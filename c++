#include <iostream>
#include <cstdlib>   
using namespace std;

int main() {

    string theUsername, thePassword;
    string user, pass;
    bool login = false;

    cout << "------------------------VCMC SIGN IN-------------------------\n";
    cout << "                                                             \n";

    cout << "Set your username: ";
    cin >> theUsername;

    cout << "Set your password: ";
    system("stty -echo");
    cin >> thePassword;
    system("stty echo");
    cout << endl;
    
    cout << "--------------------------------LOGIN------------------------\n";
    cout << "-------------------------------------------------------------\n";

    while (!login) {
        cout << "Enter username: ";
        cin >> user;

        cout << "Enter password: ";
        system("stty -echo");
        cin >> pass;
        system("stty echo");
        cout << endl;

        int i = 0;
        while (i < pass.length()) {
            cout << '*';
            i++;
        }
        cout << endl;

        if (user == theUsername && pass == thePassword) {
            login = true;
            cout << "Welcome, " << user << "." << endl;
        } else {
            cout << "Incorrect username or password" << endl << endl;
        }
    }

    return 0;
}
