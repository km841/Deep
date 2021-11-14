#include "pch.h"
#include "CountrysCapitalGame.h"

void CountrysCapitalGame::init()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	this->add("이탈리아", "로마");
	this->add("미국", "와싱턴");
	this->add("스페인", "마드리드");
	this->add("독일", "베를린");
	this->add("한국", "서울");
	this->add("일본", "도쿄");
	this->add("중국", "베이징");
	this->add("쿠웨이트", "쿠웨이트");
	this->add("베트남", "하노이");
}

bool CountrysCapitalGame::add(string country, string capital)
{
	
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == country) {
			cout << "already exists !!" << endl;
			return true;
		}
	}

	if (country == "no" && capital == "no")
		return false;

	this->v.emplace_back(country, capital);
	return true;
}

bool CountrysCapitalGame::quiz()
{
	int quizNum = rand() % v.size();
	string answer = v[quizNum].getNation();

	string input;
	cout << v[quizNum].getCountry() << "의 수도는?";
	getline(cin, input);

	if (input == "exit")
		return false;

	if (answer == input) {
		cout << "Currect !!" << endl;
		return true;
	}

	else {
		cout << "NO !!" << endl;
		return true;
	}
}

const vector<Nation>& CountrysCapitalGame::getVector()
{
	return this->v;
}
