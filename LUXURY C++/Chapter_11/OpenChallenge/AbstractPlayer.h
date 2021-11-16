#pragma once
class AbstractPlayer
{
	string name;

protected:
	static string gbb[3];

public:
	AbstractPlayer(string name) {
		this->name = name;
		gbb[0] = "가위";
		gbb[1] = "바위";
		gbb[2] = "보";
	}

	virtual string turn() = 0;
	string getName() { return name; }
};

