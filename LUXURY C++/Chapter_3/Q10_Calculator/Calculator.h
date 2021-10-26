#pragma once
class Calculator
{
public:
	int a, b;
	char oper;


public:
	void setValue(int x, int y);
	virtual int calculate() = 0;

};

class Add : public Calculator
{
public:
	int calculate() override;
};

class Sub : public Calculator
{
public:
	int calculate() override;
};

class Mul : public Calculator
{
public:
	int calculate() override;
};

class Div : public Calculator
{
public:
	int calculate() override;
};

