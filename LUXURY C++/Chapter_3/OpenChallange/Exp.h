#pragma once
class Exp
{
public:
	int base, exp;

public:
	Exp();
	Exp(int a, int b);
	Exp(int value);

	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);

	~Exp();

};

