#include "pch.h"


int main()
{
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);

	int ch;
	char lines[16];

	while (true) {
		fin.read(lines, 16);
		int n = fin.gcount();

		for (int i = 0; i < 16; i++)
		{
			if (n < 16 && i >= n) cout << '\0';
			else cout << setw(2) << setfill('0') << hex << (int)lines[i] << ' ';

			if (i == 7) cout.put('\t');
			if (i == n) cout << '\t' << '\t';
			
		}

		for (int i = 0; i < n; i++) {
			if (i == 0) cout.put('\t');
			if (isprint(lines[i])) cout << lines[i] << ' ';
			else cout << '.' << ' ';

			if (i == 7) cout.put('\t');
		}

		cout << endl;

		if (n < 16) break;
	}

	fin.close();

	return 0;
}

