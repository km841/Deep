#include <iostream>
#include <vector>
#include <conio.h>
#include <memory>
using namespace std;

void foo() { cout << "foo" << endl; }

struct IAction
{
	virtual void execute() = 0;
	virtual ~IAction() {}
};

class FunctionAction : public IAction
{
	typedef void (*FP)();
	FP handler;
public:
	FunctionAction(FP f) : handler(f) {}
	virtual void execute() { handler(); }
};

template <typename T>
class MemberAction : public IAction
{
	typedef void (T::*FP)();
	FP handler;
	T* target;

public:
	MemberAction(FP f, T* obj) : handler(f), target(obj) {}
	virtual void execute() { (target->*handler)(); }
};

template <typename T>
MemberAction<T>* action(void(T::* fp)(), T* obj) {
	return new MemberAction<T>(fp, obj);
}

FunctionAction* action(void(*fp)()) {
	return new FunctionAction(fp);
}

struct IMenuListener
{
	virtual void doCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class Dialog : public IMenuListener
{
public:
	virtual void doCommand(int id) { cout << id << endl; }
	void dialogClose() { cout << "dialog close" << endl; }

};

class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {}
	string getTitle() { return title; }
	virtual void command() = 0;
	virtual ~BaseMenu() {}
};

class MenuItem : public BaseMenu
{
	int id;
	IMenuListener* pListener = 0;
public:
	MenuItem(string s, int id) : BaseMenu(s), id(id) {}
	void setListener(IMenuListener* p) { pListener = p; }
	virtual void command() { if (pListener != 0) pListener->doCommand(id); }
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;
public:
	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* menu) { v.emplace_back(menu); }

	virtual void command() {
		const size_t size = v.size();
		while (1) {
			system("cls");
			for (int i = 0; i < size; i++)
				cout << i + 1 << ". " << v[i]->getTitle() << endl;
			cout << size + 1 << ". 돌아가기" << endl;

			int cmd;
			cout << "번호 입력 : ";
			cin >> cmd;

			if (cmd == size + 1) break;
			if (cmd < 1 || cmd > size + 1) continue;

			v[cmd-1]->command();


		}
	}
};


int main() {
	Dialog dlg;

	IAction* p1 = action(&foo);
	IAction* p2 = action(&Dialog::dialogClose, &dlg);
	
	p1->execute();
	p2->execute();
	return 0;
}

