#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n < 0)
    {
        throw 3;
    }
    if(n==0 || n==1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int main()
{
    int num;
    int result = 0;
    cout << "Enter a number : ";
    cin >> num;
    
    try
    {
        result = factorial(num);
    }
   
    catch(int error)
    {
        cout << "Number is negative" << endl;
    }
    cout << "Factorial is : " << result << endl;
    return 0;
}