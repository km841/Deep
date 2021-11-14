#include "pch.h"
#include "WordGame.h"

int main()
{
    WordGame wg;
    cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;

    wg.init();
    int ch = 1;
    while (ch == 1 || ch == 2) {
        cout << "어휘 삽입: 1, 어휘 테스트 : 2, 프로그램 종료:그외키 >> ";
        cin >> ch;
        cin.ignore();

        if (ch == 1)
        {
            cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
            while (wg.AddWord()) {}
            cout << endl;
        }

        else if (ch == 2)
        {
            cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력 시 종료." << endl;
            while (wg.Questions()) {}
            cout << endl;
        }
    
    }
}
