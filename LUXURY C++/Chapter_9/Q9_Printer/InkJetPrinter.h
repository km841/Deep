#pragma once
#include "Printer.h"

class InkJetPrinter : public Printer
{
	int availableInk;

public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) 
		: Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

	void print(int pages);
	void show();
};

