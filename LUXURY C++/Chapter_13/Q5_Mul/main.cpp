#include "pch.h"



int main()
{
	int n;
	while (true) {
		cout << "양수 입력>> ";
		cin >> n;
		try {
			if (n < 0) throw "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요";

			if (cin.fail()) {
				throw 1;
			}


			for (int i = 0; i <= 9; i++) {
				cout << n << 'x' << i << '=' << n * i << ' ';
			}
		}

		catch (const char* c) {
			cout << c << endl;
		}

		catch (int n) {
			cout << "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다." << endl;
			break;
		}

		cout << endl;
	}
	
}
