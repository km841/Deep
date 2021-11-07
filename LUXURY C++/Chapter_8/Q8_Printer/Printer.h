#pragma once
class Printer
{
protected:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;

public:
	Printer(string md, string man, int count) : 
		model(md), manufacturer(man), availableCount(count), printedCount(0) {}
	virtual void print(int pages);
};

