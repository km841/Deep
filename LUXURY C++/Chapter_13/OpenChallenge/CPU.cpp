#include "pch.h"
#include "CPU.h"

void CPU::fetch() throw(HardwareException)
{
	if (instruction == "\n") throw HardwareException("fetch 스텝", "명령 라인 없음");
}

void CPU::decode() throw(HardwareException)
{
	if (!isdigit(op1) || !isdigit(op2)) throw HardwareException("decode스텝", "피연산자 타입 예외");

	if (cmd == "ADD") { op = '+'; }
	else if (cmd == "SUB") { op = '-'; }
	else if (cmd == "MUL") { op = '*'; }
	else if (cmd == "DIV") { op = '/'; }
	else throw(HardwareException("decode스텝", "invalid 명령어 예외"));
}

void CPU::execute() throw(HardwareException)
{
	switch (op) {
	case '+':
		cout << op1 + op2 << endl;
		break;
	case '-':
		cout << op1 - op2 << endl;
		break;
	case '*':
		cout << op1 * op2 << endl;
		break;
	case '/':
		if (op2 <= 0) throw HardwareException("execute스텝", "0으로 나누기");
		cout << op1 / op2 << endl;
		break;
	}
}

void CPU::run()
{
	vector<string> v;

	getline(cin, instruction);
	
	int prev = 0, curr;
	curr = instruction.find(' ', prev);

	while (curr != string::npos) {
		v.emplace_back(instruction.substr(prev, curr - prev));
		prev = curr + 1;
		curr = instruction.find(' ', prev);
	}

	v.emplace_back(instruction.substr(prev));

	if (v.size() < 3) {
		throw HardwareException("decode스텝", "피연산자가 없음");
		return;
	}
	
	cmd = v[0];
	op1 = stringToInt(v[1]);
	op2 = stringToInt(v[2]);

	cout << setw(10);
	cout << cmd << ' ' << op1 << ' ' << op2 << ":" << '\t' << '\t';
	
	fetch();
	decode();
	execute();
}

int CPU::stringToInt(string x) throw(string)
{
	if (atoi(x.c_str()) == 0 || x.compare("0") != 0)
		throw string("decode 스텝, 피연산자 타입 예외");
	return stoi(x);
}
