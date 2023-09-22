#include<iostream>
#include<cstring>
using namespace std;


class Student 
{
public:
    int rollno;
    string name;
    int marks;

    void initStudent()
    {
        this->rollno=101;
        this->name="Madhur";
        this->marks=90;
    }

    void printStudentOnConsole()
    {   
        cout << "Student records :" << " roll no : " << rollno <<  " name : " << name << " marks : " << marks << endl;
    }

    void acceptStudentFromConsole()
    {
        cout << "Enter student roll number : " << endl;
        cin >> rollno;
        cout << "Enter student name : " << endl;
        cin >> name;
        cout << "Enter student marks " << endl;
        cin >> marks;
    }

};

int main()
{
    Student s1;
    int choice;
    do 
    {
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                s1.initStudent();
                break;
            case 2:
                s1.acceptStudentFromConsole();
                break;
            case 3:
                s1.printStudentOnConsole();
                break;
            default:
                printf("Enter correct choice\n");
                break;
        }
    } while(choice!=0);

    return 0;
}