#include <iostream>

extern "C" int get();

int main()
{
	int n, m;
	std::cout << "숫자를 입력하세요>>";
	std::cin >> n;
	std::cin.ignore();

	std::cout << "숫자를 입력하세요>>";
	std::cin >> m;
	std::cin.ignore();

	std::cout << "곱은 " << n * m << "입니다." << std::endl;
}
