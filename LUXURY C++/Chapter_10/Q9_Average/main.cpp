#include "pch.h"



int main()
{
	vector<int> v;
	int num = -1;
	double total = 0.0;
	int average;
	
	while (num != 0)
	{
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		cin >> num;
		cin.ignore();

		if (num == 0) continue;

		total += num;
		v.emplace_back(num);

		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		cout << "평균 = " << total / v.size() << endl;
	}
}
