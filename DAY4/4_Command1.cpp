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
// Command ���� : ����� ĸ��ȭ �ؼ�, ����� ����/���/������ �����ϰ� �Ѵ�.

struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v; // ���� �Դϴ�.
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {} // �̸����Ƶ� �˴ϴ�.

	void Execute() {}
};






int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




