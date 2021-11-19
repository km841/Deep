#include "pch.h"
#include "User.h"

char User::answer()
{
	char ans;
	cin >> ans;
	cin.ignore(1);

	return ans;
}
