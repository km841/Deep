#include <iostream>
#include <string>
using namespace std;

int big(int a, int b, int max=100)
{
	if (a > b) {
		if (a < max) return a;
		else return max;
	}

	else {
		if (b < max) return b;
		else return max;
	}
}

int main()
{
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	

}
