#pragma once
#include <string>
class Integer
{
private:
	int _number;
public:
	Integer(int n) : _number(n) {}
	Integer(std::string str) : _number(std::stoi(str)) {}
	int get() {
		return this->_number;
	}

	void set(int n) {
		this->_number = n;
	}

	bool isEven() {
		return ((_number % 2 == 0) == true);
	}


};

