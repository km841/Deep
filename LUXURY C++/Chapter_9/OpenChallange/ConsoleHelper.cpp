#include "ConsoleHelper.h"

void ConsoleHelper::StartGame()
{
	cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl;
	cout << endl;
}

void ConsoleHelper::NextPos()
{
	cout << "왼쪽(a), 아래(s), 위(w), 오른쪽(f) >> ";
}

void ConsoleHelper::EndGame()
{
	cout << "Human is Winner!!" << endl;
}
