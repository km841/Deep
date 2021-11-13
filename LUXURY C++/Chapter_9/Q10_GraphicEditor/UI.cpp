#include "UI.h"

void UI::StartMessage()
{ 
	cout << "그래픽 에디터입니다." << endl;
}

int UI::MainMenuSelect()
{
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	int select;
	cin >> select;
	cin.ignore();

	return select;
}

int UI::AddShapeSelect()
{
	cout << "선:1, 원:2, 사각형:3 >> ";
	int select;
	cin >> select;
	cin.ignore();

	return select;
}

int UI::DeleteShapeSelect()
{
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	int select;
	cin >> select;
	cin.ignore();

	return select;
}

void UI::ShowShapes(Shape* pStart)
{
	int count = 0;
	while (pStart != nullptr)
	{
		cout << count++ << ": " << pStart->getShape() << endl;
		pStart = pStart->getNext();
	}
}
