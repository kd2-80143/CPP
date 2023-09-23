/*
Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);
*/
#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day = 10;
    ptrDate->month = 12;
    ptrDate->year = 1996;
}

void printDateonConsole(struct Date *ptrDate)
{
    printf("Date is =  %d %d %d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter date = ");
    scanf("%d", &ptrDate->day);
    printf("Enter month = ");
    scanf("%d", &ptrDate->month);
    printf("Enter year = ");
    scanf("%d", &ptrDate->year);
}

int main()
{
    struct Date t1;

    int choice;
    
    do
    {
        printf("\nEnter a choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            initDate(&t1);
            break;
        case 2:
            printDateonConsole(&t1);
            break;
        case 3:
            acceptDateFromConsole(&t1);
            printDateonConsole(&t1);
            break;
        default:
            printf("Enter the correct choice\n");
            break;
        }

    } while (choice != 0);

    return 0;
}