#pragma once
#include "Book.h"
class ConversationBook : public Book
{
protected:
	string _lang;

public:
	ConversationBook();
	void Set(int id);
	void Show();
};

