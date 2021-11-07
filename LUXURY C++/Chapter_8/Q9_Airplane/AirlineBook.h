#pragma once
#include "Schedule.h"


class AirlineBook
{
	Schedule* Airplane;
public:
	AirlineBook() : Airplane(new Schedule[3]) {}
	void system();
	void show();


	~AirlineBook() { delete[] Airplane; }

};

