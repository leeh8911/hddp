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

// -----------------------------
// Command 패턴 : 명령을 캡슐화 해서, 명령의 저장/취소/복구가 가능하게 한다
struct ICommand {
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}
	void Execute() override { v.push_back(new Rect); }

	bool CanUndo() override { return true; }
	void Undo() override {
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
};


class AddCircleCommand : public ICommand {
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}
	void Execute() override { v.push_back(new Circle); }

	bool CanUndo() override { return true; }
	void Undo() override {
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
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

int main()
{
	std::vector<Shape*> v;
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
				
					delete pCmd;// 여기서 delete 하지 말고,
								// redo_stack.push(pCmd) 하면
								// redo도 만들 수 있음
				}
			}
		}
	}
}




