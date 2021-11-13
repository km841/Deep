#include "GraphicEditor.h"

void GraphicEditor::Add()
{
	int select = UI::AddShapeSelect() - 1;

	if (pStart == nullptr)
	{
		if (LINE == select)
			pStart = new Line();

		else if (CIRCLE == select)
			pStart = new Circle();

		else if (RECT == select)
			pStart = new Rect();

		pLast = pStart;
	}

	else
	{
		if (LINE == select)
			pLast->add(new Line());

		else if (CIRCLE == select)
			pLast->add(new Circle());

		else if (RECT == select)
			pLast->add(new Rect());

		pLast = pLast->getNext();
	}
}

void GraphicEditor::Del()
{
	int select = UI::DeleteShapeSelect();
	Shape* prev, *curr;
	prev = curr = nullptr;

	curr = pStart;

	for (int i = 0; i < select; i++)
	{
		prev = curr;
		curr = curr->getNext();
	}

	if (prev == curr)
	{
		cout << "원소가 너무 적습니다 " << endl;
		return;
	}

	if (curr->getNext()) {
		prev->add(curr->getNext());
		curr->del();
		delete curr;
	}

	else
	{
		curr->del();
		delete curr;
		prev->del();
	}
}

Shape* GraphicEditor::getStart()
{
	return pStart;
}

GraphicEditor::~GraphicEditor()
{
	if (pStart != nullptr)
	{
		delete pStart;
		pStart = nullptr;
		pLast = nullptr;
	}
}
