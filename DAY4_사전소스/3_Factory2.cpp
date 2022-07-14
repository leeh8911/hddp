#include <iostream>
#include <vector>
#include <map>
#include "helper.h"

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

	// 클래스가 자신의 객체를 만드는 "static 멤버 함수"를 제공하는 기술은
	// 아주 유용하고 널리 사용됨
	static Shape* Create() { return new Rect; }
};
// Rect 객체를 만드는 방법
// 1. Rect* p1 = new Rect;
// 2. Rect* p2 = Rect::Create();

//void fn(? arg) {
//	// 함수 인자(arg)에 따라 다른 도형을 만들고 싶다.
//	// 단, 미래에 만들어질 도형까지!
//	// if (arg == 1) new Rect; => 이렇게 하면 미래의 클래스 이름을 알아야 함
//	//							 미래의 도형은 클래스 이름을 알 수 없음
//}

//void fn(Shape* (*f)()) {
//	Shape* p = f(); // 객체 생성
//}
//
//fn(&Rect::Create); // 이 코드는 결국 "클래스 이름"을 인자로 보낸다는 의미임
//fn(&Triangle::Create);

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)();
	std::map<int, CREATOR> create_map;
public:
	void Register(int type, CREATOR f) { create_map[type] = f; }
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);
		if (ret != create_map.end()) {
			// ret는 요소의 포인터이므로, *ret는 요소(생성 함수)임
			p = ret->second();
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 이제 공장에 제품(도형)을 등록 후에 사용
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);
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