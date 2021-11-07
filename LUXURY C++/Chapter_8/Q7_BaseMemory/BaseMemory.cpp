#include "pch.h"
#include "BaseMemory.h"

BaseMemory::~BaseMemory()
{
	delete[] mem;
}
