#include <iostream>
#include <stack>
#include <conio.h>
using namespace std;

int main() {
    stack<string> languages;

    char choice;
    do {
        string lang;
        cout << "Enter a programming language: ";
        cin >> lang;

        languages.push(lang);

        cout << "Do you want to enter another language? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Languages in the stack:\n";
    while (!languages.empty()) {
        string s = languages.top();
        cout << s << "\n";
        languages.pop();
    }

    getch();
    return 0;
}
