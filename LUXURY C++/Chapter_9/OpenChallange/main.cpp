#include <iostream>
#include "Map.h"

int main()
{
    Map m;
    m.init();
    ConsoleHelper::StartGame();
    m.printMap();


    while (m.rendering())
    {
        cout << endl;
    }
}
