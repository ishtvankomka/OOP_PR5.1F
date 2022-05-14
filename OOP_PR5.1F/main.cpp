#include <iostream>
#include "Triangle.hpp"
#include "RightAngled_open.hpp"
//#include "RightAngled_close.hpp"
using namespace std;

int main() {
    try
    {
        double a, b, c;
        cout << "Set the sides:" << endl;
        cout << " a = "; cin >> a;
        cout << " b = "; cin >> b;
        cout << " c = "; cin >> c;
        RightAngled_open ro1(a, b, c);
        Display(ro1);
    }
    catch (MyException* e)
    {
        cerr << e->What() << endl;
    }
    catch (MyException& e)
    {
        cerr << e.What() << endl;
    }
    catch (Exception* e)
    {
        cerr << e->What() << endl;
    }
    catch (Exception& e)
    {
        cerr << e.What() << endl;
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        Triangle t;
        cin >> t;
        cout << t;
    }
    catch (MyException* e)
    {
        cerr << e->What() << endl;
    }
    catch (MyException& e)
    {
        cerr << e.What() << endl;
    }
    catch (Exception* e)
    {
        cerr << e->What() << endl;
    }
    catch (Exception& e)
    {
        cerr << e.What() << endl;
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
    }
    
//    try
//    {
//        double a, b, c;
//        cout << "Set the sides:" << endl;
//        cout << " a = "; cin >> a;
//        cout << " b = "; cin >> b;
//        cout << " c = "; cin >> c;
//        RightAngled_close ro1(a, b, c);
//        cout << ro1;
//    }
//    catch (MyException* e)
//    {
//        cerr << e->What() << endl;
//    }
//    catch (MyException& e)
//    {
//        cerr << e.What() << endl;
//    }
//    catch (Exception* e)
//    {
//        cerr << e->What() << endl;
//    }
//    catch (Exception& e)
//    {
//        cerr << e.What() << endl;
//    }
//    catch (invalid_argument e)
//    {
//        cerr << e.what() << endl;
//    }
    return 0;
}

