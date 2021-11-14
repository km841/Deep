#include "pch.h"
#include "Nation.h"

Nation::Nation(string country, string nation) : country(country), nation(nation) {}

string Nation::getCountry()
{
	return country;
}

string Nation::getNation()
{
	return nation;
}

bool Nation::operator==(const Nation& other)
{
	return this->country == other.country;
}

bool Nation::operator==(const string& other)
{
	return this->country == other;
}
