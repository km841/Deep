#pragma once
class BaseArray
{
private:
	int capacity;
	int* mem;

protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}

	~BaseArray() { delete[] mem; }

	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

