#pragma once
#include "Person.h"
const int GAMER_MAX = 2;

// 입력 값이 answer보다 크다면 max = ans // 작다면 반대


class UpAndDownGame
{
public:
	static int _ans;
	static int _min;
	static int _max;

	static Person p[GAMER_MAX];

public:
	UpAndDownGame();
	~UpAndDownGame();

	static bool Turn(int n);

};

