#include<iostream>
using namespace std;
class VolumeCalc
{
private:
    float length;
    float width;
    float height;
    float volume;
    
public:

    VolumeCalc()
    {
        this->length=12;
        this->width=10;
        this->height=15;
    }

    VolumeCalc(float length, float width, float height)
    {
        this->length=length;
        this->width=width;
        this->height=height;
    }
    void accept()
    {
        cout << "Enter the length " << endl;
        cin >> length;
        cout << "Enter the width " << endl;
        cin >> width;
        cout << "Enter the height" << endl;
        cin >> height;

    }

    void display()
    {
        volume = length*width*height;
        cout << "Volume = " << volume << endl;
    }

};

int menu()
{
    int choice;
    cout << "**********************************" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Insert data" << endl;
    cout << "2. Print Volume" << endl;
    cout << "3. Call Parameterized Constructor" << endl;
    cout << "**********************************" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    VolumeCalc v1;
    VolumeCalc v2(10,20,30);
    int ch;
    while((ch=menu())!=0)
    {   
        switch(ch)
        {
            case 1:
                v1.accept();
                break;
            case 2:
                v1.display();
                break;
            case 3:
                v2.display();
                break;
            default:
                cout << "Enter correct choice" << endl;
        }
    }

    return 0;
}