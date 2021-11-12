#include "Printer.h"

Printer::Printer(string model, string manufacturer, int availableCount) 
	: model(model), manufacturer(manufacturer), availableCount(availableCount), printedCount(0)
{}
