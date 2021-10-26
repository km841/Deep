#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SelectableRandom.h"
using namespace std;



int main()
{
	SelectableRandom r;
	r.SetOddOrEven(true);
  
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++)
	{
		int n = r.next();
		cout << n << ' ';
	}

	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++)
	{
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;

}

