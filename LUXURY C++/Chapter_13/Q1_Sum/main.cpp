#include "pch.h"

int sum(int a, int b) throw(const char*) {
    if (a < 0 || b < 0) throw "음수 처리 안됨";
    int total = 0;

    for (int i = a; i < b + 1; i++) {
        total += i;
    }

    return total;
}

int main()
{
    try {
        cout << sum(2, 5) << endl;
        cout << sum(-1, 5) << endl;
    }

    catch (const char* s) {
        cout << s << endl;
    }
}
