#include <iostream>
#include <string>
using namespace std;

struct UpAndDown
{
    bool Up = false;
    bool Down = false;
};

class Game
{
    string users[2];
    int currNum;
    bool initFlag = false;
    bool choiceFlag = false;

public:
    void Init()
    {
        string name;
        for (int i = 0; i < 2; i++) {
            cout << ((i == 0) ? "당신의 이름을 정하세요!" : "상대의 이름을 정하세요!") << endl;
            std::getline(cin, name);
            users[i] = name;
        }

        initFlag = true;
    }

    void SetNum(int n) {
        currNum = n;
    }

    void ChoiceMyNum()
    {
        if (!initFlag) {
            cout << "우선 초기화를 수행합니다!" << endl;
            Init();
        }

        int n;
        do
        {
            cout << "1부터 100사이의 수를 선택하세요!\n>>>";
            cin >> n;
            cin.ignore();
            cin.clear();
        } while (n <= 1 || n >= 100);

        SetNum(n);
        cout << "당신의 숫자는 " << n << "입니다!!" << endl;
    }

    UpAndDown OverTen(int n, int curr) {
        UpAndDown uad;
        if ((curr - n) >= 10)
            uad.Down = true;

        else if ((n - curr) >= 10)
            uad.Up = true;

        return uad;
    }

    string CheckNumber(int n, bool& flag) {
        string result;
        UpAndDown uad = OverTen(n, currNum);
     
        if (n < currNum) {
            result += "숫자 ";
            result += to_string(n);
            result += "은 현재 숫자보다 ";
            if (uad.Down) result += "10 이상 ";
            result += "작습니다.";
        }

        else if (n == currNum) {
            result += "정답입니다!!짝짝짝!!";
            flag = false;
        }

        else {
            result += "숫자 ";
            result += to_string(n);
            result += "은 현재 숫자보다 ";
            if (uad.Up) result += "10 이상 ";
            result += "큽니다.";
        }
        
        return result;
    }

    void StartGame()
    {
        if (!choiceFlag) {
            cout << "우선 숫자를 고릅시다!!" << endl;
            ChoiceMyNum();
        }

        int target_num;
        bool flag = true;
        while (flag)
        {
            cout << users[1] << ": ";
            cin >> target_num;
            cin.ignore();
            cin.clear();
            cout << CheckNumber(target_num, flag) << endl;
        }
    }
};

int main()
{
    Game* g = new Game;
    g->StartGame();


    delete g;
    return 0;
}

