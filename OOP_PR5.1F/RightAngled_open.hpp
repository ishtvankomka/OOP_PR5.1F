#pragma once
#include <string>
#include <iostream>
#include "Triangle.hpp"
using namespace std;

class RightAngled_open : public Triangle
{
private:
    double area;
public:
    RightAngled_open();
    RightAngled_open(double, double, double);
    RightAngled_open(RightAngled_open&);
    RightAngled_open& operator = (const RightAngled_open&);

    friend void Read(RightAngled_open&);
    friend void Display(RightAngled_open&);
    friend bool Init(Triangle&);
    
    void set_area(double value) { area = value; };
    double get_area();

    void area_calculate();
};

