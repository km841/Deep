#include "pch.h"


int main()
{
	ifstream img1("C:\\Users\\moone\\source\\repos\\Chapter_12\\Chapter_12\\pic1.jpg", ios::in | ios::binary);
	ifstream img2("C:\\Users\\moone\\source\\repos\\Chapter_12\\Chapter_12\\pic2.jpg", ios::in | ios::binary);
	
	int ch1, ch2;
	while (true) {
		ch1 = img1.get();
		ch2 = img2.get();

		if (ch1 != ch2) {
			cout << "두 이미지는 다릅니다." << endl;
			img1.close();
			img2.close();
			return 0;
		}

		if (ch1 == EOF && ch2 == EOF) {
			cout << "두 이미지는 동일합니다." << endl;
			img1.close();
			img2.close();
			return 0;
		}
	}
}

