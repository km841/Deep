#include <iostream>
#include <string>
#include "Buffer.h"
using namespace std;

Buffer& append(Buffer& buf, string word)
{
	buf.add(word);
	return buf;
}

int main()
{
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();

}

