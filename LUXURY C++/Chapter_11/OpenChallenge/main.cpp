#include "pch.h"
#include "Human.h"
#include "Computer.h"

string AbstractPlayer::gbb[3] = {};


ostream& info(ostream& os)
{
    os << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다. *****";
    return os;
}

istream& username(istream& is)
{
    cout << "선수 이름을 입력하세요>>";
    return is;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    AbstractPlayer* users[2];

    string userName;
    cout << info << endl;
    cin >> username >> userName;
    cin.ignore();
    
    users[0] = new Human(userName);
    users[1] = new Computer("Computer");
    
    int count = 0;

    while (true)
    {
        string input;
        cout << users[0]->getName() << ">>";
        getline(cin, input);

        if (input == "가위" || input == "바위" || input == "보")
        {
            string com_turn = users[1]->turn();
            cout << users[1]->getName() << ": " << com_turn << endl;;

            if ((input == "가위" && com_turn == "보") || (input == "바위" && com_turn == "가위") 
                || (input == "보" && com_turn == "바위")) {
                cout << users[0]->getName() << " is winner" << endl;
                break;
            }

            else if ((com_turn == "가위" && input == "보") || (com_turn == "바위" && input == "가위")
                || (com_turn == "보" && input == "바위")) {
                cout << users[1]->getName() << " is winner" << endl;
                break;
            }

            else
                continue;
        }
    }

    for (int i = 0; i < 2; i++)
        delete users[i];
}
