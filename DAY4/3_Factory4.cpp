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

class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(type, f);
	}
};





// ���� �ý��ۿ��� ���Ǵ� ��� ���� Ŭ������ �ݵ�� ���Ѿ� �ϴ� ��Ģ�� �����.
// ��Ģ �ڵ带 �ڵ������ϴ� ��ũ�θ� ��������.

#define DECLARE_SHAPE(classname)						\
	static Shape* Create() { return new classname; }	\
	static AutoRegister ar;

#define REGISTER_SHAPE(type, classname)		\
	AutoRegister classname::ar(type, &classname::Create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle)

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	DECLARE_SHAPE(Triangle)
};
REGISTER_SHAPE(3, Triangle)

// ��ȣ ���� ���鿡�� ���ڴ� �� ������ ��ϵǴ°� ������ �ʳ���..?
// => �� ���� �ǰ� �Դϴ�. ���忡�� ���� ��ȣ�� ��û�Ҽ� �ְ� �����ϸ� �����ϴ�.
// => factory.getNextShapeNumber(); ���� �Լ� ����


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




