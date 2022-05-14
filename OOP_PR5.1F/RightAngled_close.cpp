#include "RightAngled_close.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

RightAngled_close::RightAngled_close() {
    area = 0;
}

RightAngled_close::RightAngled_close(double a, double b, double c) {
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

RightAngled_close::RightAngled_close(RightAngled_close& f) {
    area = f.area;
    set_a(f.get_a());
    set_b(f.get_b());
    set_c(f.get_c());
}

RightAngled_close& RightAngled_close::operator = (const RightAngled_close& f) {
    area = f.area;
    set_a(f.get_a());
    set_b(f.get_b());
    set_c(f.get_c());
    return *this;
}

bool Init(RightAngled_close& f)
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
        cout << "Sides don't make right angled triangle!" << endl;
        return false;
    }
}

void RightAngled_close::area_calculate()
{
    double p = perimeter() / 2;
    double s1 = get_a();
    double s2 = get_b();
    double s3 = get_c();
    
    double s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    set_area(s);
}

double RightAngled_close::get_area() const
{
    return area;
}

void Display(RightAngled_close& f)
{
    cout << f;
    cout << " Area: " << f.get_area() << endl;
}

istream& operator >> (istream& in, RightAngled_close& f)
{
    double s1, s2, s3;
    do
    {
        cout << "Set the sides:" << endl;
            cout << " a = "; in >> s1;
            cout << " b = "; in >> s2;
            cout << " c = "; in >> s3;
            while((s1 >= s2 + s3) ||
                  (s2 >= s1 + s3) ||
                  (s3 >= s1 + s2))
                {
                    cout << "Wrong arguments to init!" << endl;
                    cout << " a = "; in >> s1;
                    cout << " b = "; in >> s2;
                    cout << " c = "; in >> s3;
                }
            f.set_a(s1);
            f.set_b(s2);
            f.set_c(s3);
            f.area_calculate();
    }
    while(!Init(f));
    return in;
}

ostream& operator << (ostream& out, const RightAngled_close& a)
{
    out << string(a);
    return out;
}

RightAngled_close::operator string () const
{
    stringstream f;
    f << "Your triangle " << endl
      << " Sides:"
      <<  " [" << get_a() << "]"
      <<  " [" << get_b() << "]"
      <<  " [" << get_c() << "]" << endl
      << " Angles:"
      << " " << angleAlfa() << "° " << angleBeta() << "° " << angleGama() << "°" << endl
      << " Perimeter: " << perimeter() << endl
      << " Area: " << get_area() << endl;
    return f.str();
}
