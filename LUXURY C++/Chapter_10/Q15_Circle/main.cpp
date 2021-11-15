#include "pch.h"
#include "Circle.h"

int main()
{
	vector<Circle*> v;

	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;

	int ch = 1;
	while (ch > 0 && ch < 4)
	{
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> ch;
		cin.ignore();

		if (ch == 1)
		{
			cout << "생성하고자 하는 원과 반지름의 이름은 >> ";
			int rad;
			string name;

			cin >> rad >> name;
			cin.ignore();
			v.emplace_back(new Circle(rad, name));
		}

		else if (ch == 2)
		{
			cout << "삭제하고자 하는 원의 이름은 >> ";
			string del;
			getline(cin, del);

			auto it = v.begin();
			while (it != v.end())
			{
				if ((*it)->getName() == del)
					it = v.erase(it);
				
				if (it == v.end())
					break;

				else it++;
			}
		}

		else if (ch == 3)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i]->getName() << endl;
			}
		}

	}
}
