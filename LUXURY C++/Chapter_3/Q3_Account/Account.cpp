#include "Account.h"

Account::Account(string owner, int id, int balance) : _owner(owner), _id(id), _balance(balance)
{
}

void Account::deposit(int money)
{
	this->_balance += money;
}

int Account::withdraw(int money)
{
	if (_balance >= money) {
		_balance -= money;
		return money;
	}

	else
		return 0;
}

int Account::inquiry()
{
	return this->_balance;
}

const string& Account::getOwner()
{
	return this->_owner;
}
