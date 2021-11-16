#include "pch.h"



int main() {

	string str;
	cout << "string으로 문자열을 읽습니다." << endl;

	while (true)
	{
		cout << "종료하려면 exit을 입력하세요 >> ";
		getline(cin, str);
		


		if (str == "exit")
		{
			cout << "프로그램을 종료합니다....";
			return 0;
		}


	}
}
