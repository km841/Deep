#pragma once
#include "Printer.h"
class LaserPrinter : public Printer
{
	int availableToner;

public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
		: Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

	void print(int pages);
	void show();


};

