#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Sample.h"
using namespace std;

int main() 
{
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;

}

