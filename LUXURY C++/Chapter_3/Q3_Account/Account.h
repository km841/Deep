#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
	string _owner;
	int _id, _balance;

public:
	Account(string owner, int id, int balance);
	void deposit(int money);

	int withdraw(int money);
	int inquiry();
	const string& getOwner();


};

