#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;
    double volume;

public:
    //constructor
    Cylinder();
    Cylinder(double radius, double height);
    //member functions
    void printVolume();
    //getter
    double getRadius();
    double getHeight();
    double getVolume();
    //setter
    void setRadius(double radius);
    void setHeight(double height);
};

#endif
