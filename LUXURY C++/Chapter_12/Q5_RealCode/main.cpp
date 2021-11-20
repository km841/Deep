#include "pch.h"


int main()
{
	ifstream fin("HangmanGame.cpp");
	bool flag = true;

	string line;
	while (getline(fin, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '/' && line[i + 1] == '/') {
				flag = false;
				break;
			}	
		}
		if (flag) cout << line << endl;
		flag = true;
	}
	return 0;
}

