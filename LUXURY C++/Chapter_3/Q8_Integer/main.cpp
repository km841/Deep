#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Integer.h"
using namespace std;



int main()
{
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << endl;
	cout << m.isEven();

}

