#include "pch.h"
#include "AirlineBook.h"
#include "Console.h"

void AirlineBook::system()
{
	int choice = 0;
	Airplane[0].setTime("07시");
	Airplane[1].setTime("12시");
	Airplane[2].setTime("17시");

	while (choice != 4)
	{
		Console::PrintMenu();


		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			Console::PrintSelectTime();
			int time = 0;
			cin >> time;
			cin.ignore();

			int pos = Console::InputPos();
			string name = Console::InputName();

			Airplane[time - 1].reservation(pos, name);
			cout << endl;
		}

		else if (choice == 2)
		{
			Console::PrintSelectTime();
			int time = 0;
			cin >> time;
			cin.ignore();

			int pos = Console::InputPos();
			string name = Console::InputName();

			Airplane[time - 1].cancel(pos, name);
			cout << endl;
		}

		else if (choice == 3)
		{
			this->show();
		}
	}
}



void AirlineBook::show()
{
	for (int i = 0; i < 3; i++)
	{
		Airplane[i].show();
	}
	cout << endl;
}
