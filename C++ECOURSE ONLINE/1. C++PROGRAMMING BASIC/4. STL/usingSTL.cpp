#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class RandFunctor {
	char ch[100]{ 0, };

public:
	RandFunctor() { srand(static_cast<unsigned int>(time(nullptr))); }
	int operator()() {
	repeat:
		int n = 1 + (rand() % 100 - 1);
		if (1 == ch[n]) goto repeat;
		ch[n] = 1;
		return n;
	}
};

class SortFunctor {
public:
	bool operator()(int a, int b) { return a > b; }
};

void Print(const vector<int>& t)
{
	for (const auto& n : t)
		cout << n << ", ";
	cout << endl;
}

int main() {
	
	vector<int> v;
	RandFunctor _random;
	vector<int>::iterator it;

	for (int i = 0; i < 10; i++) {
		v.emplace_back(_random());
	}

	int cmd = 0;
	int input = 0;

	while (1)
	{
		cin >> cmd;
		switch (cmd) {

		case 1: 
			Print(v); break;
		case 2:
			sort(begin(v), end(v), SortFunctor());
			Print(v); break;
		case 3:
			sort(begin(v), end(v), [](int a, int b) { return a < b; });
			Print(v); break;
		case 4: 
			cin >> input;
			it = find(begin(v), end(v), input);
			if (it != end(v)) v.erase(it); 
			Print(v);
			break;
		case 5:
			cin >> input;
			it = find(begin(v), end(v), input);
			if (it != end(v)) { *it = 0; }
			Print(v); break;

		case 6:
			if (20 > v.size())
			for (int i = 0; i < 10; i++) v.emplace_back(_random());
			Print(v); break;
		}
	}

	return 0;
}

