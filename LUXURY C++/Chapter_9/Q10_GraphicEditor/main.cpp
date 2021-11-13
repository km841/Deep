#include <iostream>
#include "GraphicEditor.h"
#include "UI.h"

using namespace std;


int main()
{
	GraphicEditor* gp = new GraphicEditor();
	UI::StartMessage();
	int choice = 0;

	while (choice != 4)
	{
		choice = UI::MainMenuSelect();
		
		switch (choice)
		{
		case 1:
			gp->Add();
			break;

		case 2:
			gp->Del();
			break;

		case 3:
			UI::ShowShapes(gp->getStart());
			break;
		}
	}

	delete gp;
}

