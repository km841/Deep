#pragma once
#include "Printer.h"
class printLazer : public Printer
{
	int availableToner;

public:
	printLazer(string md, string man, int count, int toner) : Printer(md, man, count), availableToner(toner) {}
	void print(int pages);
	void show();
};

