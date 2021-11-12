#include "WonToDoller.h"

WonToDoller::WonToDoller(double ratio) : Converter(ratio)
{
}

double WonToDoller::convert(double src)
{
    return src / 1010.0;
}

string WonToDoller::getSourceString()
{
    return "원";
}

string WonToDoller::getDestString()
{
    return "달러";
}
