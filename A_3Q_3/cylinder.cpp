#include "./cylinder.h"

Cylinder::Cylinder() : radius(0), height(0) , volume(0)
{
    cout << "Inside parameterless constructor " << endl;
}

Cylinder::Cylinder(double radius, double height) : radius(radius), height(height)
{
    cout << "Inside parameterized constructor" << endl;
}
//member functions
void Cylinder::printVolume()
{
    volume = 3.14*radius*radius*height;
    cout << "Volume of cylinder : " << this->volume <<  endl;
}
//getter
double Cylinder::getRadius()
{
    return this->radius;
}
double Cylinder::getHeight()
{
    return this->height;
}
double Cylinder::getVolume()
{
    return this->volume;
}
//setter
void Cylinder::setRadius(double radius)
{
    this->radius=radius;
}
void Cylinder::setHeight(double height)
{
    this->height=height;
}