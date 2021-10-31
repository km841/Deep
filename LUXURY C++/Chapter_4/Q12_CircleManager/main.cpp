#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "CircleManager.h"

using namespace std;



int main() 
{
	cout << "원의 개수 >> ";
	int choice;
	cin >> choice;
	cin.ignore();

	CircleManager cm(choice);
	cm.searchByName();
	cm.searchByArea();
}
