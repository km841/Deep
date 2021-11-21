#include "pch.h"



int main()
{
	const char* srcFile = "c:\\temp\\man.jpg";
	const char* destFile = "c:\\temp\\man_copy.jpg";

	try {
		ifstream fsrc(srcFile, ios::in | ios::binary);

		if (!fsrc) {
			throw srcFile;
		}

		ofstream fdest(destFile, ios::out | ios::binary);

		if (!fdest) {
			throw destFile;
		}


		int c;
		while ((c = fsrc.get()) != EOF) {
			fdest.put(c);
		}

		cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
		fsrc.close();
		fdest.close();

	}

	catch (const char* c) {
		cout << c << " 열기 오류" << endl;
	}
	
}
