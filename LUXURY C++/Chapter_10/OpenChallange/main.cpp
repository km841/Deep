#include "pch.h"
#include "WordGame.h"

int main()
{
    WordGame wg;
    cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;
    wg.init();
    while (wg.Questions()) {}
}
