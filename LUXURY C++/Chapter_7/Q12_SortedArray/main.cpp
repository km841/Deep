#include <iostream>
#include <string>
#include "SortedArray.h"
using namespace std;



int main()
{
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3); SortedArray b(m, 4); SortedArray c;
	
	c = a + b;

	a.show();
	b.show();
	c.show();
}
