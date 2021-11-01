#include <iostream>
#include <string>
#include "UpAndDownGame.h"
using namespace std;



int UpAndDownGame::_min = 0;
int UpAndDownGame::_max = 99;
int UpAndDownGame::_ans = 0;
Person UpAndDownGame::p[GAMER_MAX];



int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    UpAndDownGame::_ans = 1 + rand() % 99;


    cout << "Up & Down 게임을 시작합니다." << endl;
    cout << "답은 " << UpAndDownGame::_min << "과 " << UpAndDownGame::_max << "사이에 있습니다." << endl;

    UpAndDownGame uadg;

    int _turn = 0;
    while (uadg.Turn(_turn++)) { _turn %= GAMER_MAX; }

    cout << "게임이 끝났습니다!" << endl;
}
