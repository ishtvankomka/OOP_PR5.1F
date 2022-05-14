#pragma once
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Triangle.hpp"
using namespace std;

class RightAngled_close : private Triangle
{
private:
    double area;
public:
    RightAngled_close();
    RightAngled_close(double, double, double);
    RightAngled_close(RightAngled_close&);
    RightAngled_close& operator = (const RightAngled_close&);

    operator string() const;
    friend ostream& operator << (ostream&, const RightAngled_close&);
    friend istream& operator >> (istream&, RightAngled_close&);
    
    friend bool Init(RightAngled_close&);
    
    void set_area(double value) { area = value; };
    double get_area() const;

    void area_calculate();
};

