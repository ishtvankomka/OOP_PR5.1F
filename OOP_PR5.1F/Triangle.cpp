#include "Triangle.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
#define PI 3.14159265

using namespace std;

Triangle::Triangle() {
    a = 0;
    b = 0;
    c = 0;
}

Triangle::Triangle(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
}

Triangle::Triangle(Triangle& f) {
    a = f.a;
    b = f.b;
    c = f.c;
}

Triangle& Triangle::operator = (const Triangle& f) {
    a = f.a;
    b = f.b;
    c = f.c;
    return *this;
}

istream& operator >> (istream& in, Triangle& f)
{
    cout << "Set the sides:" << endl;
    cout << " a = "; in >> f.a;
    cout << " b = "; in >> f.b;
    cout << " c = "; in >> f.c;
    if (f.get_a() <= 0)
    {
        throw MyException("MyException: a side less than 0!");
    }
    if (f.get_b() <= 0)
    {
        throw MyException("MyException: b side less than 0!");
    }
    if (f.get_c() <= 0)
    {
        throw Exception("Exception: c side less than 0!");
    }
    if   ((f.a >= f.b + f.c) ||
          (f.b >= f.a + f.c) ||
          (f.c >= f.b + f.a))
        {
            throw invalid_argument("invalid_argument: The sides don't build triangle!");
        }
    return in;
}

ostream& operator << (ostream& out, const Triangle& a)
{
    out << string(a);
    return out;
}

Triangle::operator string () const
{
    stringstream f;
    f << "Your triangle " << endl
      << " Sides:"
      <<  " [" << a << "]"
      <<  " [" << b << "]"
      <<  " [" << c << "]" << endl
      << " Angles:"
      << " " << angleAlfa() << "° " << angleBeta() << "° " << angleGama() << "°" << endl
      << " Perimeter: " << perimeter() << endl;
    return f.str();
}

double Triangle::angleAlfa() const
{
    double alfa;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    if(a > b && a > c)
    {
        double beta = angleBeta();
        double gama = angleGama();
        alfa = 180 - (beta + gama);
    }
    else
    {
        double dalfa;
        if (c >= b)
        {
            dalfa = a / c;
        }
        else
        {
            dalfa = a / b;
        }
        dalfa = asin(dalfa) * 180.0 / PI;
        alfa = round(dalfa);
    }
    return alfa;
}

double Triangle::angleBeta() const
{
    double beta;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    if(b > a && b > c)
    {
        double alfa = angleAlfa();
        double gama = angleGama();
        beta = 180 - (alfa + gama);
    }
    else
    {
        double dbeta;
        if (a >= c)
        {
            dbeta = b / a;
        }
        else
        {
            dbeta = b / c;
        }
        dbeta = asin(dbeta) * 180.0 / PI;
        beta = round(dbeta);
    }
    return beta;
}

double Triangle::angleGama() const
{
    double gama;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    if(c > a && c > b)
    {
        double alfa = angleAlfa();
        double beta = angleBeta();
        gama = 180 - (alfa + beta);
    }
    else
    {
        double dgama;
        if (a >= b)
        {
            dgama = c / a;
        }
        else
        {
            dgama = c / b;
        }
        dgama = asin(dgama) * 180.0 / PI;
        gama = round(dgama);
    }
    return gama;
}

double Triangle::get_a() const
{
    return a;
}

double Triangle::get_b() const
{
    return b;
}

double Triangle::get_c() const
{
    return c;
}

double Triangle::perimeter() const
{
    double perimeter = get_a() + get_b() + get_c();
    return perimeter;
}

