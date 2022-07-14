#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
	using CREATOR = Shape * (*)();
	std::map<int, CREATOR> create_map; // {������ȣ, �����Լ�}
public:
	void Register(int type, CREATOR f) { create_map[type] = f; }


	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = (ret->second)();
		}
		return p;
	}
};

// ���忡 ��ǰ(����)�� �ڵ�����Ҷ� ����� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int type, Shape*(*f)() )
	{
		ShapeFactory::getInstance().Register(type, f);
	}
};

// main �Լ� ���� ���������� �����ڰ� ���� ȣ��˴ϴ�.
// AutoRegister ar(1, &Rect::Create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }


	// static ��� ����Ÿ�� Ư¡�� �� ���� �غ�����
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

// �� �ڵ��� �ǹ�
// Rect�� ������(Rect()) : Rect ��ü�� �����Ҷ� ���� ȣ��
// ar �� ������          : Rect Ÿ�Կ� ���� ���ʿ� 1ȸ �����
//							=> �ٸ� �Ϻ� ��ü����� �ִ� "static ������"











class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);

int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
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




