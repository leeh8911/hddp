#include <iostream>
#include <vector>
#include <stack>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

struct ICommand {
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

class AddCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}
	void Execute() override { v.push_back(CreateShape()); }

	bool CanUndo() override { return true; }
	void Undo() override {
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}

	virtual Shape* CreateShape() = 0;
};
class AddRectCommand : public AddCommand {
public:
	using AddCommand::AddCommand;
	Shape* CreateShape() { return new Rect; }
};


class AddCircleCommand : public AddCommand {
public:
	using AddCommand::AddCommand;
	Shape* CreateShape() { return new Circle; }
};

class DrawCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}
	void Execute() override { for (auto p : v) p->draw(); }

	bool CanUndo() override { return true; }
	void Undo() override {
		system("cls");
	}
};

// 여러개 명령을 저장했다가, 한번에 실행하는 매크로 명령
class MacroCommand : public ICommand {
	std::vector<ICommand*> v;
public:
	void addCommand(ICommand* p) { v.push_back(p); }

	void Execute() {
		for (auto p : v) {
			p->Execute();
		}
	}
};

int main()
{
	std::vector<Shape*> v;

	MacroCommand* mc1 = new MacroCommand;

	std::cout << "mc1 start " << std::endl;
	mc1->addCommand(new AddRectCommand(v));
	mc1->addCommand(new AddCircleCommand(v));
	mc1->addCommand(new DrawCommand(v));
	mc1->Execute();
	std::cout << "mc1 execute " << std::endl;

	MacroCommand* mc2 = new MacroCommand;

	std::cout << "mc1 start " << std::endl;
	mc2->addCommand(new AddRectCommand(v));
	mc2->addCommand(mc1);
	mc2->Execute();
	std::cout << "mc2 execute " << std::endl;

	ICommand* pCmd = nullptr;
	std::stack<ICommand*> undo_stack;
	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pCmd = new AddRectCommand(v);
			pCmd->Execute();

			undo_stack.push(pCmd);
		}
		else if (cmd == 2)
		{
			pCmd = new AddCircleCommand(v);
			pCmd->Execute();

			undo_stack.push(pCmd);
		}
		else if (cmd == 9)
		{
			pCmd = new DrawCommand(v);
			pCmd->Execute();

			undo_stack.push(pCmd);
		}
		else if (cmd == 0) {
			if (!undo_stack.empty()) {
				pCmd = undo_stack.top();
				undo_stack.pop();
				if (pCmd->CanUndo()) {
					pCmd->Undo();

					delete pCmd;
				}
			}
		}
	}
}