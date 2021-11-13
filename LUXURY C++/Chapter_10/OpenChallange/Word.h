#pragma once
class Word
{
	string kor, eng;

public:
	Word(string kor, string eng) : kor(kor), eng(eng) {}
	string getEng() { return eng; }
	string getKor() { return kor; }
};

