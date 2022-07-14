#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}


	// prototype ���� : �ڽ��� ���纻�� ����� �����Լ��� ����ϴ� ������ ����
	// ���忡 �ߺ� ��ü�� ����� ����..
	// �ʿ��Ҷ� ���� "Clone()" �� ȣ���ؼ� ���纻�� ���� ���

	virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	Shape* Clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	Shape* Clone() override { return new Circle(*this); }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
	std::map<int, Shape*> prototype_map; // �ߺ� ���� ��
public:
	void Register(int type, Shape* sample) 
	{
		prototype_map[type] = sample;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototype_map.find(type);

		if (ret != prototype_map.end())
		{
			p = prototype_map[type]->Clone(); // ���� ������ ���纻����
											// ���ο� ���� ����
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();


	// ���� ���忡 ��ǰ(����)�� ����Ŀ� ����մϴ�.
	// �Ʒ� �ڵ�� ���忡
	// 1. ��ü ���
	// 2. Ŭ���� ��� <= ����(�ش� Ŭ������ ��ü�� �����ϴ� �Լ� ���)
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);

	// �̹����� ���忡 "���� ���Ǵ� ��ü"�� ����� ���ô�.
	Rect* redRect  = new Rect; // ������ ũ�� 10�̶�� ����
	Rect* blueRect = new Rect; // �Ķ��� ũ�� 5�̶�� ����
	Circle* whiteCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, whiteCircle);






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

// Factor2�� => 5������ ����



