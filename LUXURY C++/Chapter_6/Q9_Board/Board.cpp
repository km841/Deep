#include "Board.h"

void Board::add(string message)
{
	strArr[arrPos++] = message;
}

void Board::print()
{
	cout << "************ 게시판입니다 ************" << endl;
	for (int i = 0; i < arrPos; i++)
		cout << i << ":" << strArr[i] << endl;
}
