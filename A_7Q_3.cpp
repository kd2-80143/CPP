#include <iostream>
using namespace std;

class Employee
{
protected:
    int id;
    float sal;
    string designation;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0;
        this->designation="";
    }
    Employee(int id, float sal, string designation)
    {
        this->id = id;
        this->sal = sal;
        this->designation=designation;
    }
    int get_id()
    {
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    virtual void accept()
    {
        cout << "Enter employee id " << endl;
        cin >> this->id;
        cout << "Enter employee salary " << endl;
        cin >> this->sal;
        cout << "Enter employee designation " << endl;
        cin >> this->designation;
    }
    virtual void display()
    {
        cout << "Employee id : " << this->id << endl;
        cout << "Employee salary : " << this->sal << endl;
        cout << "Employee designation :" << this->designation << endl;
    }
};

class Manager : virtual public Employee
{
protected:
    float bonus;

public:
    Manager()
    {
        this->id = 0;
        this->sal = 0;
        this->bonus = 0;
        this->designation="Manager";
    }
    Manager(int id, float sal, float bonus, string designation)
    {
        this->id = id;
        this->sal = sal;
        this->bonus = bonus;
        this->designation=this->designation;
    }
    float get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        //Employee::accept();
        cout << "Enter employee Manager id " << endl;
        cin >> this->id;
        cout << "Enter employee Manager salary " << endl;
        cin >> this->sal;
        cout << "Enter Manager bonus" << endl;
        cin >> this->bonus;
        cout << "Enter designation " << endl;
        cin >> this->designation;
    }
    void display()
    {   
        //Employee::display();
        cout << "Employee Manager id : " << this->id << endl;
        cout << "Employee Manager salary : " << this->sal << endl;
        cout << "Employee Manager Bonus : " << this->bonus << endl;
        cout << "Designation : " << this->designation << endl;
    }
protected:
    void accept_manager()
    {
        cout << "Enter manager Bonus " << endl;
        cin >> this->bonus;
    }
    void display_manager()
    {
        cout << "Manager Bonus : " << this->bonus << endl;
    }
};

class Salesman : virtual public Employee
{
protected:
    float comm;

public:
    Salesman()
    {
        this->comm = 0;
        this->id = 0;
        this->sal = 0;
        this->designation="Salesman";
    }
    Salesman(int id, float sal, float comm, string designation)
    {
        this->comm = comm;
        this->id = id;
        this->sal = sal;
        this->designation= designation;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void accept()
    {
        //Employee::accept();
        cout << "Enter employee Salesman id " << endl;
        cin >> this->id;
        cout << "Enter employee Salesman salary " << endl;
        cin >> this->sal;
        cout << "Enter Salesman Commission " << endl;
        cin >> this->comm;
        cout << "Enter designation " << endl;
        cin >> this->designation;
    }
    void display()
    {
        //Employee::display();
        cout << "Employee Salesman id : " << this->id << endl;
        cout << "Employee Salesman salary : " << this->sal << endl;
        cout << "Employee Salesman Commission : " << this->comm << endl;
        cout << "Designation " << this->designation << endl;
    }
protected:
    void accept_salesman()
    {
        cout << "Enter commission :" << endl;
        cin >> this->comm;
    }
    void display_salesman()
    {   
        cout << "Commission :"  << this->comm << endl;
    }
};

class Sales_Manager : public Manager, Salesman
{
public:
    Sales_Manager()
    {
        Employee::id=0;
        Employee::sal=0;
        Manager::bonus=0;
        Salesman::comm=0;
        Employee::designation="Sales Manager";
    }
    Sales_Manager(int id, float sal, float bonus, float comm, string designation)
    {
        Employee::id=id;
        Employee::sal=sal;
        Manager::bonus=bonus;
        Salesman::comm=comm;
        Employee::designation="";
    }
    void accept()
    {
        
        cout << "Enter employee salesmanager id " << endl;
        cin >> this->id;
        cout << "Enter employee salesmanager salary " << endl;
        cin >> this->sal;
        cout << "Enter salesmanager bonus" << endl;
        cin >> this->bonus;
        cout << "Enter salesmanager Commission" << endl;
        cin >> this->comm;
        cout << "Enter designation :" << endl;
        cin >> this->designation;
    }
    void display()
    {
       
        cout << "Employee salesmanager id : " << this->id << endl;
        cout << "Employee salesmanager salary : " << this->sal << endl;
        cout << "Employee salesmanager Bonus : " << this->bonus << endl;
        cout << "Employee salesmanager Commission : " << this->comm << endl;
        cout << "Designation :" <<  this->designation << endl;
    }
};

void countEmployees(Employee **ptr, int index)
{
    int manager_count = 0;
    int salesman_count = 0;
    int salesmanager_count = 0;
    for (int i = 0; i < index; i++)
    {
        if (typeid(*ptr[i]) == typeid(Manager))
        {
            manager_count++;
        }
        else if(typeid(*ptr[i]) == typeid(Salesman))
        {
            salesman_count++;
        }
        else if(typeid(*ptr[i]) == typeid(Sales_Manager))
        {
            salesmanager_count++;
        }
    }
    cout << "Number of Managers : " << manager_count << endl;
    cout << "Number of Salesman : " << salesman_count << endl;
    cout << "Number of Salesmanager :" << salesmanager_count << endl; 
}

void displayEmployees(Employee **ptr, int index)
{
    // int manager_count = 0;
    // int salesman_count = 0;
    // int salesmanager_count = 0;
    for (int i = 0; i < index ; i++)
    {
        if (typeid(*ptr[i]) == typeid(Manager))
        {
            cout << "Manager" << endl;
        }
        else if(typeid(*ptr[i]) == typeid(Salesman))
        {
            cout << "Salesman" << endl;
        }
        else if(typeid(*ptr[i]) == typeid(Sales_Manager))
        {
            cout << "Salesmanager" << endl;
        }
    }
    // cout << "Number of Managers : " << manager_count << endl;
    // cout << "Number of Salesman : " << salesman_count << endl;
    // cout << "Number of Salesmanager :" << salesmanager_count << endl; 
}

int menu()
{
    int choice;
    cout << "***************************" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Accept Manager " << endl;
    cout << "2. Accept Salesman " << endl;
    cout << "3. Accept Salesmanager" << endl;
    cout << "4. Display the count of all employees wrt designation" << endl;
    cout << "5. Display respective designation employees" << endl;
    //cout << "6. Display all employees";
    cout << "*****************************" << endl;
    cout << "Enter your choice ";
    cin >> choice;
    return choice;
}
int main()
{
    Employee *arr[10];
    int index = 0;
    int ch;
    while((ch=menu())!=0)
    {
        switch(ch)
        {
            case 1:
            if(index < 10)
            {
                arr[index] = new Manager();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Array is full, cannot accept Manager";
            }
            break;
            case 2:
            if( index < 10)
            {
                arr[index] = new Salesman();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Array is full, cannot accept Salesman";
            }
            break;
            case 3:
            if( index < 10)
            {
                arr[index] = new Sales_Manager();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Array is full, cannot accept Salesmanager";
            }
            break;
            case 4:
            countEmployees(arr,index);
            break;
            case 5:
            displayEmployees(arr,index);
            break;
            default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }
    for (int i = 0; i < index; i++)
    {
        delete arr[i];
    }

    return 0;
}