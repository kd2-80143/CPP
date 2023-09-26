/*
Q2. Stack is a Last-In-First-Out data structure.
Write a Stack class. It implements stack using Dynamically allocated array. 
Stack size should be passed in parameterized constructor. 
If size is not given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().
*/
#include<iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *arr;
public:
    
    //parameterized constructor
    Stack(int size)
    {
        arr = new int[size];
        this->size=size;
        top=-1;
    }
    void push(int x)
    {
        if (size-top>1)
        {
            top++;
            arr[top] = x;
        
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop()
    {
        if(top==0)
        {
            cout<<"Stack underflow "<<endl;
        }
        else
        {
            top--;
        }

    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"There are no elements in the array"<<endl;
            return 0;
        }
        else
        {
            return arr[top];
        }

    }
    bool isEmpty()
    {   
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(top==size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        while(top!=-1)
        {
            cout << arr[top--] << endl;
        }
    }
};

int main()
{
    Stack s(5);
    s.push(15);
    s.push(25);
    s.push(35);
    s.push(45);
    s.push(55);
    //s.pop();
    cout << "Peak element is " << s.peek() << endl;
    s.print();
    
    cout << s.isEmpty() << endl;
    
    return 0;
}