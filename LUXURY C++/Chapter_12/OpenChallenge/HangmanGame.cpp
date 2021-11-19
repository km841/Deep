#include "pch.h"
#include "HangmanGame.h"

HangmanGame::HangmanGame() : u(new User)
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

void HangmanGame::fileLoad()
{
	ifstream fin("words.txt", ios::in);
	string word;

	while (getline(fin, word))
		v.emplace_back(word);
}

bool HangmanGame::question()
{
	bool flag = true;
	int randValue = rand() % 25143;
	string ans_word = v[randValue];

	int pos_arr[2] = {ans_word.size(), ans_word.size()};
	int cnt = 0;
	bool condition[2] = {false, false};

	while (pos_arr[0] == ans_word.size() || pos_arr[1] == ans_word.size())
	{
		int randPos = rand() % ans_word.size();
		if (randPos != pos_arr[0] && randPos != pos_arr[1])
			pos_arr[cnt++] = randPos;
	}

	if (pos_arr[0] > pos_arr[1]) {
		int temp;
		temp = pos_arr[0];
		pos_arr[0] = pos_arr[1];
		pos_arr[1] = temp;
	}

	while (condition[0] != true || condition[1] != true)
	{
		if (!flag) break;
		for (int i = 0; i < ans_word.size(); i++)
		{
			if ((i == pos_arr[0] && condition[0] == false) 
				|| i == pos_arr[1] && condition[1] == false) {
				cout << '-';
			}

			else cout << ans_word[i];
		}

		cout << endl << ">>";
		char user_ans = u->answer();

		for (int i = 0; i < 2; i++)
		{
			if (condition[i] == true)
				continue;

			else if (ans_word[pos_arr[i]] == user_ans) {
				condition[i] = true;
				break;
			}

			else {
				u->game_try();
				if (u->get_try() == 0) {
					cout << "5번 실패하셨습니다." << endl;
					flag = false;	
				}

				break;
			}
		}
	}

	cout << ans_word << endl;
	cout << "Next(y/n)?";
	char c;
	cin >> c;
	cin.ignore();

	if (c == 'y') {
		u->init();
		return true;
	}
	else
		return false;
	
}
