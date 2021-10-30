#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int* nums = new int[5];
	double sum = 0;
	
	for (int i = 0; i < 5; i++)
	{
		cin >> nums[i];
		sum += nums[i];
	}

	cout << "평균 " << sum / 5.0 << endl;

	delete[] nums;

}

