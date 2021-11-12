#include "LoopAdder.h"

void LoopAdder::read()
{
	cout << name << ":" << endl;
	cout << "처음 수에서 두번쨰 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write()
{
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run()
{
	read();
	sum = calculate();
	write();
}
