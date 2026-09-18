#include <iostream>
#include <cstdlib>  
using namespace std;

int main() {

    string theUsername, thePassword;
    string user, pass;
    bool login = false;

    cout << "                          VCMC LOGIN\n";
    cout << "                                                             \n";

    cout << "Set your username: ";
    cin >> theUsername;

    cout << "Set your password: ";
    system("stty -echo");     
    cin >> thePassword;
    system("stty echo");      
    cout << endl;

    while (!login) {
        cout << "Enter username: ";
        cin >> user;

        cout << "Enter password: ";
        system("stty -echo");   
        cin >> pass;
        system("stty echo");    
        cout << endl;

        
        for (int i = 0; i < pass.length(); i++) {
            cout << '*';
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
