#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

void swap(Circle& c1, Circle& c2)
{
    Circle temp = c1;
    c1 = c2;
    c2 = temp;
}

int main()
{
    Circle c1(5);
    Circle c2(3);
    
    swap(c1, c2);

    cout << "c1 : " << c1.radius << endl;
    cout << "c2 : " << c2.radius << endl;
}

