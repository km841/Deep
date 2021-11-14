#pragma once
class Nation
{
	string country, nation;
public:
	Nation(string country, string nation);
	string getCountry();
	string getNation();
	bool operator== (const Nation& other);
	bool operator== (const string& other);
};

