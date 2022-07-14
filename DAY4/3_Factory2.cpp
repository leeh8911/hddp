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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// Ŭ������ �ڽ��� ��ü�� ����� "static ��� �Լ�"�� �����ϴ� �����
	// ���� �����ϰ� �θ� ���˴ϴ�.
	static Shape* Create() { return new Rect; }
};
// Rect��ü�� ����� ���
// 1. Rect* p1 = new Rect;
// 2. Rect* p2 = Rect::Create();

/*
void fn(int arg)
{
	// �Լ�����(arg)���� �ٸ� ������ ����� �ʹ�.
	// ��, �̷��� ������� �������� !!
	if (arg == 1) new Rect; //�̷��� �ϸ� Ŭ���� �̸��� �˾ƾ� �մϴ�
							// �̷��� ������ Ŭ���� �̸��� �˼� �����ϴ�.
}
*/
/*
void fn(Shape* (*f)())
{
	Shape* p = f(); // ��ü ����
}
fn( &Rect::Create ); // �� �ڵ�� �ᱹ "Ŭ�����̸�"�� ���ڷ� ������ �ǹ� �Դϴ�.
fn( &Triangle::Create);
*/

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
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
			// ret �� ����� ������ �̹Ƿ� pair �� �������Դϴ�.
			// pair.first �� key, pair.second �� value(�Լ�������)
			p = (ret->second)();  
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();

	// ���� ���忡 ��ǰ(����)�� ����Ŀ� ����մϴ�.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);


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




