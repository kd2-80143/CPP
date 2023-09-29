/*Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
datatype*/

#include<iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    //constructor
    Date()
    {
        this->day=0;
        this->month=0;
        this->year=0;
    }
    Date(int day, int month, int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    //getter
    int get_day()
    {
        return this->day;
    }
    int get_month()
    {
        return this->month;
    }
    int get_year()
    {
        return this->year;
    }
    //setter
    void set_day(int day)
    {
        this->day=day;
    }
    void set_month(int month)
    {
        this->month=month;
    }
    void set_year(int year)
    {
        this->year=year;
    }
    //facilitators
    void accept()
    {
        cout << "Enter day " << endl;
        cin >> this->day;
        cout << "Enter month " << endl;
        cin >> this->month;
        cout << "Enter year " << endl;
        cin >> this->year;

    }

    void display()
    {
        cout << "Date : " << this->day << "/" << this->month << "/" << this->year << endl;
        cout << "Leap Year : " << is_leap_year(this->year) << endl;
    }

    bool is_leap_year(int year)
    {
        if(year%400==0 || (year%4==0 && year%100!=0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


class Employee
{
private:
    int id;
    float sal;
    string dept;
    Date doj;  //Association - composition
public:
    //constructors
    Employee()
    {
        this->id=0;
        this->sal=0;
        this->dept="";
    }
    Employee(int id,float sal,string dept, int day, int month, int year) : doj(day, month, year)
    {
        this->id=id;
        this->sal=sal;
        this->dept=dept;
    }
    //getter
    int get_id()
    {
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }
    string get_dept()
    {
        return this->dept;
    }
    Date get_joining_date()
    {
        return this->doj;
    }
    //setter
    void set_id(int id)
    {
        this->id=id;
    }
    void set_sal(float sal)
    {
        this->sal=sal;
    }
    void set_dept(string dept)
    {
        this->dept=dept;
    }
    void set_joining_date(Date doj)
    {
        this->doj=doj;
    }
    //facilitator
    void accept()
    {
        cout << "Enter Employee id : ";
        cin >> this->id;
        cout << "Enter Salary : ";
        cin >> this->sal;
        cout << "Enter dept no : ";
        cin >> this->dept;
        doj.accept();
    }
    void display()
    {
        cout << "Employee id : " << this->id << endl;
        cout << "Employee salary : " << this->sal << endl;
        cout << "Employee dept : " << this->dept << endl;
        doj.display();
    }

};

class Person
{
private:
    string name;
    string addr;
    Date dob;  // Association - Composition

public:
    //constructor
    Person()
    {
        this->name="";
        this->addr="";
    }
    Person(string name, string addr, int day, int month, int year) : dob(day,month,year)
    {
        this->name=name;
        this->addr=addr;
    }
    //getter
    string get_name()
    {
        return this->name;
    }
    string get_addr()
    {
        return this->addr;
    }
    Date get_birth_date()
    {
        return this->dob;
    }
    //setter
    void set_name(string name)
    {
        this->name=name;
    }
    void set_addr(string addr)
    {
        this->addr=addr;
    }
    void set_birth_date(Date dob)
    {
        this->dob=dob;
    }
    void accept()
    {
        cout << "Enter person's name : ";
        cin >> this->name;
        cout << "Enter person's address :";
        cin >> this->addr;
        dob.accept();
    }
    void display()
    {
        cout << "Person Name : " << this->name << endl;
        cout << "Person Address : "<< this->addr << endl;
        dob.display(); 
    }
};



int main()
{
    Employee e1;
    //e1.accept();
    //e1.display();
    //e1.get_dept();
    //e1.set_dept("Sunbeam");
    //e1.set_id(1055);
    //e1.set_sal(2500);
    //e1.set_joining_date(Date(10,8,2009));
    e1.accept();
    e1.display();
    
    //cout << e1.get_id() << endl;

    Person p1;
    //p1.accept();
    //p1.set_name("Yash");
    //p1.set_addr("PrateekVistara");
    //p1.set_birth_date(Date(19,8,1996));
    p1.accept();
    p1.display();
    //cout << p1.get_name() << endl;
    //cout << p1.get_addr() << endl;
    //cout << p1.get_birth_date() << endl;

    //Date d1;
    //cout << d1.is_leap_year(2018) << endl;
    return 0;
}