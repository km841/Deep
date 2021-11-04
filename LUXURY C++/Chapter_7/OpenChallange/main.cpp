#include <iostream>
#include <string>
#include "Histogram.h"
using namespace std;

int main()
{
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by";
	song << 'k' << 'i' << 't';
	!song;
}
