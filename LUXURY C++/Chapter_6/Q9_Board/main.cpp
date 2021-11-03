#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

string Board::strArr[100] = {};
int Board::arrPos = 0;

int main()
{
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}
