#include "pch.h"



int main() {
	int ch;
	cin.ignore(100, ';'); 
	while ((ch = cin.get()) != EOF) {
		cout << (char)ch;
		if (ch == '\n') {
			cin.ignore(100, ';');
		}
	}
}
