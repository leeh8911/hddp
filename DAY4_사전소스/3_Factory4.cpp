#include <iostream>
#include <vector>
#include <map>
#include "helper.h"


// �� �ڵ忡�� ��� �����
// 1. Rect::Create() �Լ�
//	=> new Rect; �̷��� ����� "Ŭ�����̸�"�� �ʿ���
//					Ŭ���� �̸��� �ڷ� ������ ������ �� ����
//					�׷е�, ���ڿ��� ��ü ������ �ȵ�
//					string s = "Rect";
//					s�� ��ü ���� �� �� ����...

// auto f = Rect::Create;
// f()	�̷��� ������� �Լ� �ּ� �ʿ�
//		�Լ� �ּҴ� �ڷᱸ�� ���� �����ϰ�
//		������ �ּҷ� ��ü ���� ����

// 2. ������ vs static ������ (C#�� ����)
// Rect r1;
// Rect r2; // ������ ȣ��.. ��ü�� �ѹ��� ȣ���. ��ü �ʱ�ȭ

// Rect::ar // Rect Ŭ������ ���� ���ʿ� 1ȸ ȣ��
//			// Rect Ŭ���� ��ü�� �ʱ�ȭ�� Ȱ�� ����
//			// C++���� ������ C#�� �ִ� static ������ ����
//			// C++������ �Ʒ��� ���� static ��� �����ͷ� �����ϰ� ����

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
	std::map<int, CREATOR> create_map;
public:
	void Register(int type, CREATOR f) { create_map[type] = f; }
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);
		if (ret != create_map.end()) {
			p = ret->second();
		}

		return p;
	}
};

class AutoRegister {
public:
	AutoRegister(int type, Shape* (*f)()) {
		ShapeFactory::getInstance().Register(type, f);
	}
};

// ���� �� �ý��ۿ��� ���Ǵ� ���� Ŭ������ �ݵ�� ���Ѿ� �ϴ� ��Ģ�� ����
// ��Ģ �ڵ带 �ڵ������ϴ� ��ũ�θ� ����
#define DECLARE_SHAPE(class_name)							\
	static Shape* Create() { return new class_name; }	\
	static AutoRegister ar;									

#define REGISTER_SHAPE(type, class_name)					\
	AutoRegister class_name::ar(type, &class_name::Create);

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect);

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle);

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	DECLARE_SHAPE(Triangle)
};
REGISTER_SHAPE(3, Triangle);

// ��ȣ ���� ���鿡�� ���ڴ� �� ������ ��ϵǴ°� ������ �ʳ�?
// => ���� �ǰ�, ���忡�� ���� ��ȣ�� ��û�� �� �ִٸ�.. 
//

int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::getInstance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (1 <= cmd && cmd <= 7) {
			Shape* p = factory.Create(cmd);
			if (p != nullptr) {
				v.push_back(p);
			}
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