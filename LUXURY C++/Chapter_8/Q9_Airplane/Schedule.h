#pragma once
#include "Seat.h"
class Schedule
{
	string time;
	Seat* schedule;

public:
	Schedule() : schedule(new Seat[8]) {}
	void setTime(string time);
	void reservation(int pos, string name); // 예약
	void cancel(int pos, string name); // 취소
	void show(); // 보기
	~Schedule() { delete[] schedule; }

};

