#include "pch.h"
#include "Schedule.h"

void Schedule::setTime(string time)
{
	this->time = time;
}

void Schedule::reservation(int pos, string name)
{
	if (schedule[pos - 1].isEmpty())
	{
		schedule[pos - 1].setUser(name);
	}
}

void Schedule::cancel(int pos, string name)
{
	if (!schedule[pos - 1].isEmpty())
	{
		schedule[pos - 1].delArea();
	}
}

void Schedule::show()
{
	cout << time << ":" << '\t';
	for (int i = 0; i < 8; i++)
	{
		cout << schedule[i].getUser() << '\t';
	}
	cout << endl;
}
