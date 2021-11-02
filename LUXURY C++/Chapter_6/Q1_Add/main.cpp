#include <iostream>
#include <string>
using namespace std;

int add(int n1[], int size, int n2[] = nullptr)
{
	int _res = 0;

	for (int i = 0; i < size; i++)
	{
		_res += n1[i];
		if (n2 != nullptr)
			_res += n2[i];
	}

	return _res;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, 10 };
	
	int c = add(a, 5);
	int d = add(a, 5, b);

	cout << c << endl;
	cout << d << endl;

	

}
