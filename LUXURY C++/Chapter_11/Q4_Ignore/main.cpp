#include "pch.h"



int main() {
	int ch;
	while ((ch = cin.get()) != EOF) {
		if (ch == ';') {
			cin.ignore(100, '\n');
			cout << endl;
			cin.get();
		}
		cout << (char)ch;
	}
}
