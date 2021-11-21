#include "pch.h"
#include "HardwareException.h"

HardwareException::HardwareException(string step, string msg) : step(step), msg(msg)
{}

string HardwareException::getStep()
{
	return step;
}

string HardwareException::getMsg()
{
	return msg;
}

void HardwareException::setMsg(string msg)
{
	this->msg = msg;
}

void HardwareException::what()
{
	cout << endl << step << ", " << msg << endl;
}
