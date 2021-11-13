#pragma once
#include "Shape.h"
class UI
{
public:
	static void StartMessage();
	static int MainMenuSelect();
	static int AddShapeSelect();
	static int DeleteShapeSelect();
	static void ShowShapes(Shape* pStart);

};

