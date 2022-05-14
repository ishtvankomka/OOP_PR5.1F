#include "RightAngled_open.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

RightAngled_open::RightAngled_open() {
    area = 0;
}

RightAngled_open::RightAngled_open(double a, double b, double c) {
    if (a <= 0)
    {
        throw invalid_argument("invalid_argument: a side less than 0!");
    }
    else
        if (b <= 0)
    {
        throw MyException("MyException: b side less than 0!");
    }
    else
        if (c <= 0)
        {
            throw Exception("Exception: c side less than 0!");
        }
    else
    {
        set_a(a);
        set_b(b);
        set_c(c);
    }
}

RightAngled_open::RightAngled_open(RightAngled_open& f) {
    area = f.area;
    set_a(f.get_a());
    set_b(f.get_b());
    set_c(f.get_c());
}

RightAngled_open& RightAngled_open::operator = (const RightAngled_open& f) {
    area = f.area;
    set_a(f.get_a());
    set_b(f.get_b());
    set_c(f.get_c());
    return *this;
}

bool Init(Triangle& f)
{
    double d1 = f.get_a();
    double d2 = f.get_b();
    double d3 = f.get_c();

    if(f.get_b() > d1)
    {
        d1 = f.get_b();
        d2 = f.get_a();
    }
    if(f.get_c() > d1)
    {
        d1 = f.get_c();
        d2 = f.get_a();
        d3 = f.get_b();
    }

    if ((d1*d1) == (d2*d2 + d3*d3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void RightAngled_open::area_calculate()
{
    double p = perimeter() / 2;
    double s1 = get_a();
    double s2 = get_b();
    double s3 = get_c();
    
    double s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    set_area(s);
}

double RightAngled_open::get_area()
{
    area_calculate();
    return area;
}

void Read(RightAngled_open& f)
{
    do
    {
        cin >> f;
    }
    while(!Init(f));
}

void Display(RightAngled_open& f)
{
    cout << f;
    cout << " Area: " << f.get_area() << endl;
}
