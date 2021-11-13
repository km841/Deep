#pragma once
#include "UI.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

enum
{
	LINE,
	CIRCLE,
	RECT
};

class GraphicEditor
{
	Shape* pStart, *pLast;

public:
	void Add();
	void Del();
	Shape* getStart();
	~GraphicEditor();
};

