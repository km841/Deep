#include "Human.h"

Human::Human(int startX, int startY, int distance) : GameObject(startX, startY, distance)
{

}

void Human::move()
{
	string input;

	while (true) {
		ConsoleHelper::NextPos();
		getline(cin, input);

		if (input == "a") {
			if (x <= 0)
			{
				cout << "왼쪽으로 갈 수 없습니다! 다시 입력하세요." << endl;
				continue;
			}

			x -= this->distance;
			break;
		}

		else if (input == "s") {
			if (y >= 10)
			{
				cout << "아래쪽으로 갈 수 없습니다! 다시 입력하세요." << endl;
				continue;
			}

			y += this->distance;
			break;
		}

		else if (input == "d") {
			if (y <= 0)
			{
				cout << "위쪽으로 갈 수 없습니다! 다시 입력하세요." << endl;
				continue;
			}

			y -= this->distance;
			break;
		}

		else if (input == "f") {
			if (x >= 20)
			{
				cout << "오른쪽으로 갈 수 없습니다! 다시 입력하세요." << endl;
				continue;
			}

			x += this->distance;
			break;
		}
	}



}

char Human::getShape()
{
	return 'H';
}

Human::~Human()
{}
