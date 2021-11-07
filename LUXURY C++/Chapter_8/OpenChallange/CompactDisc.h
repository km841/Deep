#pragma once
#include "Product.h"
class CompactDisc : public Product
{
	string _albumName;
	string _singer;
public:

	CompactDisc();
	void Set(int id);
	void Show();
};

