#include <iostream>
using namespace std;

class Insufficient_funds
{
public:
    int accid;
    double cur_balance;
    double withdraw_amount;

public:
    Insufficient_funds()
    {
        this->accid = 0;
        this->cur_balance = 0;
        this->withdraw_amount = 0;
    }
    Insufficient_funds(int accid, double cur_balance)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
    }
    Insufficient_funds(int accid, double cur_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout << "ERROR : Id or balance is wrongly input" << endl;
    }
    void display1()
    {
        cout << "ERROR : Amount entered should be greater than zero" << endl;
    }
    void display2()
    {
        cout << "ERROR : Withdrawl amount is greater than current balance" << endl;
    }
};

enum Account_type
{
    SAVING,
    CURRENT,
    DMAT
};

class Account
{
private:
    int id;
    double balance;
    Account_type type;

public:
    Account()
    {
        this->id = 0;
        this->balance = 0;
    }
    Account(int id, Account_type type, double balance)
    {
        this->id = id;
        this->balance = balance;
        this->type = type;
    }
    void accept()
    {

        int acc_type;
        cout << "Enter Employee ID :";
        cin >> this->id;
        if (id <= 0)
            throw Insufficient_funds(this->id, this->balance);
        cout << "Enter account balance :";
        cin >> this->balance;
        if (balance < 500)
            throw Insufficient_funds(this->id, this->balance);
        cout << "What type of account you want :" << endl;
        cout << "0. SAVING" << endl;
        cout << "1. CURRENT" << endl;
        cout << "2. DMAT" << endl;

        cin >> acc_type;
        this->type = Account_type(acc_type);
    }
    void display()
    {
        cout << "Account ID : " << this->id << endl;
        cout << "Account Balance : " << this->balance << endl;
        cout << "Account Type : " << this->type << endl;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    int get_id()
    {
        return this->id;
    }
    double get_balance()
    {
        return this->balance;
    }
    Account_type get_type()
    {
        return this->type;
    }
    void set_type(Account_type type)
    {
        this->type = type;
    }
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw Insufficient_funds(this->id, this->balance, amount);
        }
        this->balance += amount;
        cout << "Total Amount after Deposit :" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw Insufficient_funds(this->id, this->balance, amount);
        }
        if (this->balance < amount)
        {
            throw Insufficient_funds(this->id, this->balance, amount);
        }
        this->balance -= amount;
        cout << "Total Amount after Withdrawl :" << balance << endl;
    }
};

int menu()
{
    int choice;
    cout << "*******************************" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Deposit in Account" << endl;
    cout << "3. Withdraw from Account" << endl;
    cout << "4. Display Account" << endl;
    cout << "*******************************" << endl;
    cout << "Enter your choice";
    cin >> choice;
    return choice;
}

int main()
{
    int count = 0;
    int ch;
    int accno;
    double amount;
    int index = 0;
    Account *arr[5];
    while ((ch = menu()) != 0)
    {
        switch (ch)
        {
        case 1:
            if (count < 5)
            {
                arr[index] = new Account;
                try
                {
                    arr[index]->accept();
                }
                catch (Insufficient_funds error03)
                {
                    error03.display();
                }
                count++;
            }
            break;
        case 2:
            if (index < 5)
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "Enter your account number ";
                    cin >> accno;
                    if (arr[i]->get_id() == accno)
                    {
                        cout << "Enter amount to deposit";
                        cin >> amount;
                        try 
                        {
                            arr[i]->deposit(amount);
                        }
                        catch (Insufficient_funds error)
                        {
                            error.display1();
                        }
                    }
                }
            }
            else
            {
                cout << "Cannot do any operations" << endl;
            }
            break;
        case 3:
            if (index < 5)
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "Enter your account number ";
                    cin >> accno;
                    if (arr[i]->get_id() == accno)
                    {
                        cout << "Enter amount to withdraw";
                        cin >> amount;
                        try
                        {
                            arr[i]->withdraw(amount);
                        }
                        catch (Insufficient_funds error02)
                        {
                            error02.display2();
                        }
                    }
                }
            }
            else
            {
                cout << "Cannot do any operations" << endl;
            }
            break;
        case 4:
            if (index < 5)
            {
                cout << "Enter your account number ";
                cin >> accno;
                for (int i = 0; i < count; i++)
                {

                    if (arr[i]->get_id() == accno)
                    {
                        arr[i]->display();
                        break;
                    }
                }
            }
            break;
        default:
            cout << "Enter correct choice " << endl;
            break;
        }
    }
    return 0;
}
