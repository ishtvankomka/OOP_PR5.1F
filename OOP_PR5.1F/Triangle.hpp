#pragma once
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "Exception.h"
#include "MyException.h"
using namespace std;

class Triangle
{
private:
    double a, b, c;
public:
    Triangle();
    Triangle(double, double, double);
    Triangle(Triangle&);
    Triangle& operator = (const Triangle&);
    
    operator string() const;
    friend ostream& operator << (ostream&, const Triangle&);
    friend istream& operator >> (istream&, Triangle&);

    void set_a(double value) { a = value; };
    void set_b(double value) { b = value; };
    void set_c(double value) { c = value; };
    double get_a() const;
    double get_b() const;
    double get_c() const;
    
    double angleAlfa() const;
    double angleBeta() const;
    double angleGama() const;
    double perimeter() const;
};

