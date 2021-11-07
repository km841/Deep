#include "pch.h"
#include "Seat.h"

Seat::Seat(string name) : userName(name) {}

void Seat::setUser(string name)
{
    this->userName = name;
}

string Seat::getUser()
{
    return userName;
}

void Seat::delArea()
{
    userName = "---";
}

bool Seat::isEmpty()
{
    return (userName == "---");
}
