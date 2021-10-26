#include "Date.h"

int charToInt(char c)
{
    if (c >= 0x30 && c <= 0x39)
    {
        return c - 0x30;
    }
}

Date::Date(int year, int month, int day) : _year(year), _month(month), _day(day)
{
}

Date::Date(string date)
{
    const char* cstr = date.c_str();
    const size_t size = strlen(cstr);
    int tmp = 0;
    int arr[3] = { 0, };
    int arrCnt = 0;

    for (int i = 0; i < size+1; i++)
    {
        if ((cstr[i] == '/' && tmp != 0) || cstr[i] == '\0')
        {
            arr[arrCnt++] = tmp;
            tmp = 0;
        }

        if (std::isdigit(cstr[i]))
        {
            if (i != 0) tmp *= 10;
            tmp += charToInt(cstr[i]);
        }
    }
    insertArr(arr);
}

void Date::show()
{
    cout << _year << "년" << _month << "월" << _day << "일" << endl;
}

int Date::getYear()
{
    return _year;
}

int Date::getMonth()
{
    return _month;
}

int Date::getDay()
{
    return _day;
}

void Date::insertArr(int arr[])
{
    _year = arr[0];
    _month = arr[1];
    _day = arr[2];
}

