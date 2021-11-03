#include <iostream>
#include <string>
#include "Random.h"
using namespace std;


int main()
{
	Random r;
	r.seed();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << r.nextInt(1, 100) << ' ';
	}
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << r.nextAlphabet() << ' ';
	}
	cout << endl;

	cout << "랜덤한 실수를 10개 출력합니다" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << r.nextDouble() << ' ';
	}
	cout << endl;
}
