/*
Q2. Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
Instead of char[] use string datatype
*/
#include<iostream>
#include<string>
using namespace std;
class Address 
{
private:
    int pin;
    string building;
    string street;
    string city;

public:

    Address()
    {
        this->pin=401322;
        this->building="Silver-City";
        this->street="Sector-93A";
        this->city="Noida";

    }

    Address(string building, string street, string city,int pin)
    {
        
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }
    

    void accept()
    {
        cout << "Enter pin :" << endl;
        cin >> pin;
        cout << "Enter building :" << endl;
        cin >> building;
        cout << "Enter street :" << endl;
        cin >> street;
        cout << "Enter city :" << endl;
        cin >> city;
    }

    void display()
    {
        cout << "Address = " << " pin : " << this->pin << " building : " << this->building << " street : " << this->street << " city : " << this->city << endl;
    }
    
    //getter - inspector
    int get_pin()
    {
        return this->pin;
    }

    string get_city()
    {
        return this->city;
    }

    string get_street()
    {
        return this->street;
    }

    string get_building()
    {
        return this->building;
    }

    //setter - mutator
    void setPin(int pin)
    {
        this->pin = pin;
    }

    void setBuilding(string building)
    {
        this->building = building;
    }

    void setStreet(string street)
    {
        this->street = street;
    }

    void setCity(string city)
    {
        this->city = city;
    }

};

int menu()
{   
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Insert details" << endl;
    cout << "2. Display details" << endl;
    cout << "3. Getter" << endl;
    cout << "4. Setter" << endl;
    cout << "5. Call constructor" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{   
    Address a1;
    int ch;

    Address a2 ("Expressview","Sector-93B","Noida",201501);

    while((ch=menu())!=0)
    {
        switch(ch)
        {
            case 1:
            a1.accept();
            break;

            case 2:
            a1.display();
            
            break;
            
            case 3:
            cout << "Value of a1.pin : " << a1.get_pin() << endl;
            cout << "Value of a1.building : " << a1.get_building() << endl;
            cout << "Value of a1.street : " << a1.get_street() << endl;
            cout << "Value of a1.city : " << a1.get_city() << endl;
            break;

            case 4:
            a1.setPin(203403);
            a1.setBuilding("ATS");
            a1.setStreet("Sector-93");
            a1.setCity("Noida");
            a1.display();
            break;

            case 5:
            a2.display();


            default:
            cout << "Enter correct choice " << endl;
        }
    }
    cout << "Thanks for using our application " << endl;

    
    
    return 0;
}