#include <iostream>
#include "WhileLoopAdder.h"
#include "DoWhileLoopAdder.h"
using namespace std;


int main()
{
	WhileLoopAdder whileLoop("while Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");


	whileLoop.run();
	doWhileLoop.run();
}
