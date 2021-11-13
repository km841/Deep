#include "pch.h"
#include "WordGame.h"

WordGame::WordGame() : wordSize(0)
{}

void WordGame::init()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	this->add("인간", "human");
	this->add("사회", "society");
	this->add("인형", "dall");
	this->add("감정", "emotion");
	this->add("그림", "painting");
	this->add("거래", "trade");
	this->add("사과", "apple");
	this->add("돌", "stone");
}

void WordGame::add(string kor, string eng)
{
	this->wordBook.emplace_back(kor, eng);
	this->wordSize++;
}

bool WordGame::Questions()
{
	int checked[10] = { 0, };
	int checkCnt = 0;
	int randValue;
	bool flag = true;

	while (checkCnt != 4)
	{
		randValue = rand() % wordSize;
		for (int i = 0; i < checkCnt; i++)
		{
			if (checked[i] == randValue)
				flag = false;
		}

		if (flag) {
			checked[checkCnt++] = randValue;
		}

		flag = true;
	}

	int answerNum = rand() % 4;
	cout << wordBook[checked[answerNum]].getEng() << "?" << endl;
	for (int i = 0; i < checkCnt; i++)
		cout << "(" << i + 1 << ") " << wordBook[checked[i]].getKor() << " ";

	cout << ":>";

	int choice = 0;
	cin >> choice;
	cin.ignore();

	if (choice == 0 || choice > 4)
		return false;

	if ((choice -1) == answerNum)
		cout << "Excellent !!" << endl;

	else
		cout << "No. !!" << endl;

	return true;
}
