#pragma once
class Seat
{
	string userName;

public:
	Seat(string name = "---");
	void setUser(string name);
	string getUser();
	void delArea();
	bool isEmpty();

};

