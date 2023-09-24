/*
Q3. Write a class to find volume of a Cylinder by using following members. (volume of Cylinder=3.14 * radius * radius *height) (write a menu driven code for it and also use modular approach)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
getVolume()
printVolume()
Initialize members using constructor member initializer list.
*/

#include "./cylinder.h"
#include "./menu.h"

int main()
{
    Cylinder c1;
    Cylinder c2(15,15);
    Emenu ch;
    while((ch=menu())!=EXIT)
    {
        switch(ch)
        {
            case DEFAULT_CONSTRUCTOR:
            c1.printVolume();
            break;
            case PARAMETERIZED_CONSTRUCTOR:
            c2.printVolume();
            break;
            case GETTER:
            cout << "The value of c1.radius : " << c1.getRadius() << endl;
            cout << "The value of c1.height : " << c1.getHeight() << endl;
            cout << "the value of c1.volume : " << c1.getVolume() << endl;
            break;
            case SETTER:
            c1.setHeight(20);
            c1.setRadius(20);
            c1.printVolume();
            break;
            default:
            cout << "Enter correct choice" << endl;
            break;
        }
    }
  
    cout << "Thanks for using this application" << endl;
   
    
    
    return 0;
   
}