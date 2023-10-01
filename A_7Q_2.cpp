#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    double price;
    string type;

public:
    virtual void Accept() = 0;
    virtual void display() = 0;

    string get_bType()
    {
        return this->type;
    }
    double get_bPrice()
    {
        return this->price;
    }
    string get_tType()
    {
        return this->type;
    }
    double get_tPrice()
    {
        return this->price;
    }
};


class Book : public Product
{
private:
    string Author;

public:
    Book()
    {
        this->Author = "";
        this->type = "B";
    }
    void Accept()
    {
        cout << "Enter book id :";
        cin >> this->id;
        cout << "Enter book title :";
        cin >> this->title;
        cout << "Enter book price :";
        cin >> this->price;
        cout << "Enter Author name :";
        cin >> this->Author;
    }
    void display()
    {
        cout << "Book Id :" << this->id << endl;
        cout << "Book Title :" << this->title << endl;
        cout << "Book Price :" << this->price << endl;
        cout << "Author Name " << this->Author << endl;
    }
    string get_bType()
    {
        return this->type;
    }
    double get_bPrice()
    {
        return this->price;
    }
    
};

class Tape : public Product
{
private:
    string Artist;

public:
    Tape()
    {
        this->Artist = "";
        this->type = "T";
    }
    void Accept()
    {
        cout << "Enter Tape id :";
        cin >> this->id;
        cout << "Enter Tape title :";
        cin >> this->title;
        cout << "Enter Tape price :";
        cin >> this->price;
        cout << "Enter Artist name :";
        cin >> this->Artist;
    }
    void display()
    {
        cout << "Tape Id :" << this->id << endl;
        cout << "Tape Title :" << this->title << endl;
        cout << "Tape Price :" << this->price << endl;
        cout << "Artist Name " << this->Artist << endl;
    }
    string get_tType()
    {
        return this->type;
    }
    double get_tPrice()
    {
        return this->price;
    }
};

int menu()
{
    int choice;
    cout << "**************************" << endl;
    ;
    cout << "0. Exit" << endl;
    cout << "1. Accept Book" << endl;
    cout << "2. Accept Tape" << endl;
    cout << "3. Display" << endl;
    cout << "4. Calculate" << endl;
    cout << "***************************" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

double CalculateBill(Product *p[])
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
    {
        if(p[i]->get_bType() == "B")
        {
            sum = sum + p[i]->get_bPrice() - p[i]->get_bPrice()*0.10;

        }
        else if(p[i]->get_tType() == "T")
        {
            sum = sum + p[i]->get_tPrice() - p[i]->get_tPrice()*0.05;
        }
    }
    return sum;
}
int main()
{
    int index = 0;
    double result = 0;
    Product *arr[3];
    int ch;
    while ((ch = menu()) != 0)
    {
        switch (ch)
        {
        case 1:
            if (index < 3)
            {
                arr[index] = new Book;
                arr[index]->Accept();

                index++;
            }
            else
            {
                cout << "Array is full, cannot accept book" << endl;
            }

            break;
        case 2:
            if (index < 3)
            {
                arr[index] = new Tape;
                arr[index]->Accept();
                index++;
            }
            else
            {
                cout << "Array is full, cannot accept tape" << endl;
            }
            break;
        case 3:
            for(int i = 0; i < index; i++)
            { 
                arr[i]->display();
            }
            break;
        case 4:
            result = CalculateBill(arr);
            cout << "Final Bill : " << result << endl;
            break;
        default:
            cout << "Entered wrong choice " << endl;
            break;
        }
    }

    for(int i = 0; i < index; i++)
    {
        delete arr[i];
    }
}