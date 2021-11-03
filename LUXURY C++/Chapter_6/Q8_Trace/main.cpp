#include <iostream>
#include <string>
#include "Trace.h"
using namespace std;

vector<TraceTuple> Trace::_traceVector = vector<TraceTuple>();

void f()
{
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}


int main()
{
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");
	Trace::print("f()");
	Trace::print();
}
