#include<iostream>
using namespace std;

class Time
{
private:
    int h;
    int m;
    int s;

public:
    //parameterless constructor
    Time()
    {
        this->h=10;
        this->m=10;
        this->s=0;
    }
    //parameterized constructor
    Time(int h, int m, int s)
    {
        this->h=h;
        this->m=m;
        this->s=s;
    }
    //getter
    int getHour()
    {
        return this->h;
    }
    int getMinute()
    {
        return this->m;
    }
    int getSeconds()
    {
        return this->s;
    }
    //setter
    void setHour()
    {
        cout<<"Enter hours : ";
        cin>>this->h;
    }
    void setMinute()
    {   
        cout<<"Enter minutes : ";
        cin>>this->m;
    }
    void setSeconds()
    {   
        cout<<"Enter seconds : ";
        cin>>this->s;
    }
    //facilitator
    void printTime()
    {
        cout << "Time is : " << h << " : " << m << " : " << s << endl;
    }

};

int main()
{
    int n;
    cout << "Enter the number of elements " << endl;
    cin >> n;
    Time **t1 = new Time *[n];

    for (int i = 0; i < n; i++)
        t1[i] = new Time();

    for (int i = 0; i < n ; i++)
    {
        t1[i]->setHour();
        t1[i]->setMinute();
        t1[i]->setSeconds();
        cout << "Value at t1.hr : " << t1[i]->getHour() << endl;
        cout << "Value at t1.min : " << t1[i]->getMinute() << endl;
        cout << "Value at t1.sec : " << t1[i]->getSeconds() << endl;
    }   

    for (int i=0;i<n;i++)
    {
        t1[i]->printTime();
    }

    //deallocating
    for(int i = 0; i < n; i++)
        delete t1[i];

    delete[] t1;
 return 0;   
}