#include "./menu.h"
#include<iostream>
using namespace std;

Emenu menu()
{
    int choice;
    cout << "******************************" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Default Constructor" << endl;
    cout << "2. Parameterized Constructor" << endl;
    cout << "3. Getter" << endl;
    cout << "4. Setter" << endl;
    cout << "******************************" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    return Emenu(choice);
}
