#include "pch.h"

class Phone {
	string name;
	string telnum;
	string address;

public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}

	friend istream& operator>> (istream& ist, Phone& p);
	friend ostream& operator<< (ostream& ost, Phone& p);
};

int main()
{
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}




istream& operator>>(istream& ist, Phone& p)
{
	cout << "이름:";
	getline(cin, p.name);

	cout << "전화번호:";
	getline(cin, p.telnum);

	cout << "주소:";
	getline(cin, p.address);

	return ist;
}

ostream& operator<<(ostream& ost, Phone& p)
{
	ost << "(" << p.name << "," << p.telnum << "," << p.address << ")";
	return ost;
}
