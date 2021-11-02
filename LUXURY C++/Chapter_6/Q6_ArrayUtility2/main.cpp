#include <iostream>
#include <string>
#include "ArrayUtility2.h"
using namespace std;


int main()
{
	cout << "정수 5개를 입력하라, 배열 x에 삽입한다>>";
	int x[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> x[i];
	}

	cout << "정수 5개를 입력하라, 배열 y에 삽입한다>>";
	int y[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> y[i];
	}

	cout << "합친 정수 배열을 출력한다" << endl;
	int* z = ArrayUtility2::concat(x, y, 5);
	for (int i = 0; i < 10; i++)
		cout << z[i] << ' ';
	cout << endl;
	
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. ";

	int ret = 0;
	int* a = ArrayUtility2::remove(x, y, 5, ret);

	cout << "개수는 " << ret << endl;
	for (int i = 0; i < ret; i++)
		cout << a[i] << ' ';
	cout << endl;

	delete[] z;
	delete[] a;

}
