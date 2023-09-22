#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        this->day=10;
        this->month=12;
        this->year=2021;
    }
    void printDateOnConsole()
    {
        printf("Date = %d : %d : %d\n",day,month,year);
    }
    void acceptDateFromConsole()
    {
        printf("Enter the day = ");
        scanf("%d", &day);
        printf("Enter the month =");
        scanf("%d", &month);
        printf("Enter the year =");
        scanf("%d", &year);
    }
    bool isLeapYear()
    {
        printf("Enter the year");
        int a;
        scanf("%d",&a);
        if(a%4 == 0 && a%100 != 0)
        {
            return true;
        }
        else if(a%400==0)
        {
            return true;
        }
        else {
            return false;
        }

        return false;
    }
};



int main()
{
    struct Date t1;
    int choice;
    do
    {
        printf("Enter a choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            
        case 1:
            t1.initDate();
            break;
        case 2:
            t1.printDateOnConsole();
            break;
        case 3:
            t1.acceptDateFromConsole();
            t1.printDateOnConsole();
            break;
        case 4:
            bool result;
            result = t1.isLeapYear();
            if(result==true)
            {
                printf("It's a leap year\n");
            }
            else
            {
                printf("It's not a leap year\n");
            }
            break;
        default:
            printf("\nEnter correct choice\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
