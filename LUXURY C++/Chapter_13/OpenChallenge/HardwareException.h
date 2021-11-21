#pragma once
class HardwareException
{
	string step;
	string msg;

public:
	HardwareException(string step = "", string msg = "");
	string getStep();
	string getMsg();
	void setMsg(string msg);
	void what();
};

