#pragma once
#include "Printer.h"
class printInkJet : public Printer
{
	int availableInk;

public:
	printInkJet(string md, string man, int count, int ink) : Printer(md, man, count), availableInk(ink) {}
	void print(int pages);
	void show();
};

