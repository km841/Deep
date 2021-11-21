#include "pch.h"

int get() throw(const char*) {
	int n;

	cout << "0~9 사이의 정수 입력 >> ";
	cin >> n;
	cin.ignore();

	if (n >= 0 && n <= 9)
		return n;
	else throw "input fault";
	
}

int main()
{
	int n, m;
	while (true) {
		try {
			n = get();
			m = get();
			cout << n << "x" << m << "=" << n * m << endl;
		}

		catch (const char* c) {
			cout << c << endl;
		}
	}
	
}
