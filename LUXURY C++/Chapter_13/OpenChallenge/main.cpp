#include "pch.h"
#include "CPU.h"
#include "HardwareException.h"



int main()
{
	CPU cpu;

	while (true) {
		try {
			cpu.run();
		}
		
		catch (HardwareException& hw) {
			hw.what();
		}
		catch (string& s) {
			cout << s << endl;
		}
		
	}
}
