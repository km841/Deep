#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Date
{

private:
	int _year, _month, _day;

public:
	Date(int year, int month, int day);
	Date(string date);
	/*Date(const char* date);*/

	void show();
	int getYear();
	int getMonth();
	int getDay();
	void insertArr(int arr[]);


};

