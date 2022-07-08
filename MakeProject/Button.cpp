#include "pch.h"
#include "Button.h"

Button::Button(std::wstring name, std::wstring addr, POINT pos)
	: addr(addr), name(name), pos(pos)
{

}

bool Button::SetAddr(const std::wstring& newAddr)
{
	this->addr = newAddr;
	return true;
}

bool Button::SetName(const std::wstring& newName)
{
	this->name = newName;
	return true;
}


bool Button::SetColor(COLORREF newColor)
{
	color = newColor;
	return true;
}


bool Button::SetPos(POINT newPos)
{
	pos = newPos;
	return true;
}

bool Button::SetHWND(HWND newHwnd)
{
	hwnd = newHwnd;
	return true;
}

std::wstring Button::GetAddr()
{
	return this->addr;
}

std::wstring Button::GetName()
{
	return this->name;
}

bool Button::SetID(int id)
{
	this->id = id;
	return true;
}

POINT Button::GetPos()
{
	return this->pos;
}

COLORREF Button::GetColor()
{
	return this->color;
}

HWND Button::GetHWND()
{
	return this->hwnd;
}

SIZE Button::GetSize()
{
	return this->size;
}

int Button::GetID()
{
	return 0;
}
