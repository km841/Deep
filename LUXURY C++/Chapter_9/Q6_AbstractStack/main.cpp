#include <iostream>
#include "IntStack.h"
using namespace std;


int main()
{
	IntStack it(10);

	for (int i = 0; i < 11; i++)
	{
		if (it.push(i)) cout << i << " ";
		else cout << endl << "스택이 가득 찼습니다!!" << endl;
	}

	int result = 0;
	while (it.size()) {
		if (it.pop(result))
		{
			cout << result << " ";
		}
	}

	cout << endl;
	cout << "스택의 원소를 모두 소진하고 while문 탈출" << endl;
}
