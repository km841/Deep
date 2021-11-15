#include "pch.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"


int main()
{
	vector<Shape*> v;
	
	int ch = 1;
	cout << "그래픽 에디터입니다." << endl;

	while (ch > 0 && ch < 4)
	{
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> ch;
		cin.ignore();

		if (ch == 1)
		{
			cout << "선:1, 원:2, 사각형:3 >> ";
			int ch_shape;
			cin >> ch_shape;
			cin.ignore();

			switch (ch_shape)
			{
			case 1:
				v.emplace_back(new Line());
				break;

			case 2:
				v.emplace_back(new Circle());
				break;

			case 3:
				v.emplace_back(new Rect());
				break;
			}
		}

		else if (ch == 2)
		{
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			int ch_del;
			cin >> ch_del;
			cin.ignore();

			auto it = v.begin() + ch_del;
			it = v.erase(it);
		}

		else if (ch == 3)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << i << ": ";
				v[i]->paint();
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}


}
