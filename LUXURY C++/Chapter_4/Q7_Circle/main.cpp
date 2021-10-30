#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

int main() 
{
	const int CIRCLE_SIZE = 3;
	const int CIRCLE_MAX_SIZE = 100;

	Circle* circles = new Circle[CIRCLE_SIZE];
	int count = 0;
	
	for (int i = 0; i < CIRCLE_SIZE; i++)
	{
		cout << "원 " << i+1 << "의 반지름 >> ";
		int size = 0;

		cin >> size;
		cin.ignore();

		circles[i].setRadius(size);

		if (circles[i].getArea() >= CIRCLE_MAX_SIZE) count++;
	}

	cout << "면적이 100보다 큰 원은 " << count << "개 입니다.";

	
}
