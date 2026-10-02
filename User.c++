#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string maskedInput() {
    system("stty -echo");
    string pass;
    cin >> pass;
    system("stty echo");
    cout << string(pass.length(), '*') << endl;
    return pass;
}

void userMenu(vector<string> &users, vector<string> &passes, vector<string> &roles) {
    string choice, nu, np;

    do {
        cout << "\n1. Create User\n2. View Users\n3. Exit\nChoose: ";
        cin >> choice;

        if (choice == "1") {
            cout << "New Username: "; cin >> nu;
            cout << "New Password: "; np = maskedInput();
            users.push_back(nu);
            passes.push_back(np);
            roles.push_back("User");
            cout << "User created.\n" << endl;

        } else if (choice == "2") {
            for (int i = 0; i < users.size(); i++)
                cout << users[i] << " - " << roles[i] << endl;
        }
    } while (choice != "3");
}

void adminMenu(vector<string> &users, vector<string> &passes, vector<string> &roles) {
    string choice, nu, np;

    do {
        cout << "\n1. Create Admin\n2. Exit\nChoose: ";
        cin >> choice;

        if (choice == "1") {
            cout << "New Admin Username: "; cin >> nu;
            cout << "New Admin Password: "; np = maskedInput();
            users.push_back(nu);
            passes.push_back(np);
            roles.push_back("Admin");
            cout << "Admin created.\n";
        }
    } while (choice != "2");
}

int main() {
    string superUser = "RusselAdmin", superPass = "456";
    vector<string> users, passes, roles;

    string user, pass, choice;

    while (true) {
        cout << "\n1. Login\n2. Exit\nChoose: ";
        cin >> choice;

        if (choice == "2") break;
        if (choice != "1") continue;

        cout << "Username: "; cin >> user;
        cout << "Password: "; pass = maskedInput();

        if (user == superUser && pass == superPass) {
            cout << "Welcome, " << user << " (Super Account)." << endl;
            adminMenu(users, passes, roles);

        } else {
            bool found = false;
            for (int i = 0; i < users.size(); i++) {
                if (user == users[i] && pass == passes[i]) {
                    found = true;
                    cout << "Welcome, " << user << " (" << roles[i] << ")." << endl;
                    if (roles[i] == "Admin") userMenu(users, passes, roles);
                    break;
                }
            }
            if (!found) cout << "Incorrect username or password\n" << endl;
        }
    }

    return 0;
}