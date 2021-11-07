#pragma once
class Product
{
	
public:
	Product();
	string _prodCont;
	string _prodName;
	int _price;
	int _id;

public:

	virtual void Set(int id);
	virtual void Show();
};

