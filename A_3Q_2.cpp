#include<iostream>
using namespace std;

class Toolbooth
{
private:
    unsigned int pc;
    unsigned int npc;
    double amt;
public:
    Toolbooth()
    {
        this->pc=0;
        this->npc=0;
        this->amt=0;
    }
    void payingCar()
    {
        this->pc = pc+1;
        this->amt = amt+0.50;
    }
    void nopayCar()
    {
        this->npc = npc+1;
        //this->amt = amt;
    }
    void printOnConsole()
    {
        cout << "Total number of cars paying toll " << this->pc << endl;
        cout << "Total number of cars not paying toll " << this->npc << endl;
        cout << "Total amount recovered " << this->amt << endl;
    }
};

int menu()
{
    int choice;
    cout << "*************************" << endl;
    cout << "0.Exit" << endl;
    cout << "1. Do you want to pay the bill?" << endl;
    cout << "2. Do you want to skip the bill? " << endl;
    cout << "3. Print slip" << endl;
    cout << "*************************" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    Toolbooth tb;
    int ch;
    while((ch=menu())!=0)
    {
        switch(ch)
        {
            case 1: 
            tb.payingCar();
            break;
            case 2:
            tb.nopayCar();
            break;
            case 3:
            tb.printOnConsole();
            break;
            default:
            cout << "Enter correct choice " << endl;
            break;
        }
    }
    return 0;  
}