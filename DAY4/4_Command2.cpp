#include <iostream>
#include <vector>
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

//----------------------

struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

// ������ �߰��ϴ� ������ ������ �ڵ尡 ���� �ֽ��ϴ�.
// ������ �ڵ尡 ���ٸ� ���Ŭ������ ���� �����մϴ�.
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back( CreateShape() ); }
	bool CanUndo() override { return true; }

	void Undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
	// Factory Method ���� : ��ü�� ����� ���� �������̽��� �����ϰ� ���������
	//					    � ������ ��ü�� �������� �Ļ� Ŭ������ �����Ѵ�.
	// template method �� ������ ���������, ���ϴ� �����Լ��� �ϴ� ����
	// �˰������� ������ �ƴ� "��ü�� ����"�� �����Ѵ�.
	virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; // ������ ���

	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; 

	Shape* CreateShape() override { return new Circle; }
};



class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override
	{
		for (auto p : v) p->draw();
	}
	bool CanUndo() override { return true; }

	void Undo() override
	{
		system("cls");
	}
};


#include <stack>

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
		else if (cmd == 0)
		{
			if (!undo_stack.empty())
			{
				pCmd = undo_stack.top();

				undo_stack.pop();

				if (pCmd->CanUndo())
					pCmd->Undo();

				delete pCmd; 
			}
		}
	}
}



