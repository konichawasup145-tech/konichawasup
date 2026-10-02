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

void userMenu(vector<string>& users, vector<string>& passes, vector<string>& roles) {
    string choice, nu, np;

    do {
        cout << "\n--- User Menu ---\n";
        cout << "1. Create User\n";
        cout << "2. View Users\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == "1") {
            cout << "New Username: ";
            cin >> nu;

            cout << "New Password: ";
            np = maskedInput();

            users.push_back(nu);
            passes.push_back(np);
            roles.push_back("User");

            cout << "User created successfully.\n";

        } else if (choice == "2") {
            cout << "\n--- Registered Users ---\n";

            if (users.empty()) {
                cout << "No users registered.\n";
            } else {
                for (size_t i = 0; i < users.size(); i++) {
                    cout << users[i] << " - " << roles[i] << endl;
                }
            }

        } else if (choice != "3") {
            cout << "Invalid choice.\n";
        }

    } while (choice != "3");
}

void adminMenu(vector<string>& users, vector<string>& passes, vector<string>& roles) {
    string choice, nu, np;

    do {
        cout << "\n--- Super Admin Menu ---\n";
        cout << "1. Create Admin\n";
        cout << "2. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == "1") {
            cout << "New Admin Username: ";
            cin >> nu;

            cout << "New Admin Password: ";
            np = maskedInput();

            users.push_back(nu);
            passes.push_back(np);
            roles.push_back("Admin");

            cout << "Admin created successfully.\n";

        } else if (choice != "2") {
            cout << "Invalid choice.\n";
        }

    } while (choice != "2");
}

int main() {
    string superUser = "RusselAdmin";
    string superPass = "456";

    vector<string> users;
    vector<string> passes;
    vector<string> roles;

    string user, pass, choice;

    while (true) {
        cout << "\n--- Login System ---\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == "2") {
            cout << "Goodbye!\n";
            break;
        }

        if (choice != "1") {
            cout << "Invalid choice.\n";
            continue;
        }

        cout << "Username: ";
        cin >> user;

        cout << "Password: ";
        pass = maskedInput();

        // Check super admin
        if (user == superUser && pass == superPass) {
            cout << "\nWelcome, " << user
                 << " (Super Account).\n";

            adminMenu(users, passes, roles);
            continue;
        }

        // Check registered users/admins
        bool found = false;

        for (size_t i = 0; i < users.size(); i++) {
            if (user == users[i] && pass == passes[i]) {
                found = true;

                cout << "\nWelcome, " << user
                     << " (" << roles[i] << ").\n";

                if (roles[i] == "Admin") {
                    userMenu(users, passes, roles);
                }

                break;
            }
        }

        if (!found) {
            cout << "Incorrect username or password.\n";
        }
    }

    return 0;
}
