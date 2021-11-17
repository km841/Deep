#pragma once
class Container
{
	string name;
	size_t size;

public:
	Container(string name) : name(name), size(3) {}
	void fill() { size = 3; }
	size_t getSize() { return size; }
	void use() { size--; }
	bool isEmpty() { return size == 0; }
	virtual string getName() = 0;
};

