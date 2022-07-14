#include <iostream>
#include <vector>
#include <map>
#include "helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	// prototype 패턴 : 자신의 복사본을 만드는 가상함수를 제공하는 디자인 패턴
	// 공장에 견본 객체를 등록해 놓고..
	// 필요할 때 마다 "Clone()"을 호출해서 복사본을 만들어서 사용
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

	std::map<int, Shape*> prototype_map; // 견본 도형 등록
public:
	void Register(int type, Shape* sample) { prototype_map[type] = sample; }
	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototype_map.find(type);
		if (ret != prototype_map.end()) {
			p = prototype_map[type]->Clone(); // 기존 도형의 복사본으로
												// 새로운 도형 생성
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 이제 공장에 제품(도형)을 등록 후에 사용
	// 아래 코드는 공장에
	// 1. 객체를 등록
	// 2. 클래스를 등록 <= 정답 (해당 클래스의 객체를 생성하는 함수 등록)
	//factory.Register(1, &Rect::Create);
	//factory.Register(2, &Circle::Create);

	// 이번에는 공장에 "자주 사용되는 객체"를 등록!
	Rect* redRect = new Rect; // 빨간색에 크기가 10이라 가정
	Rect* blueRect = new Rect;  // 파란색에 크기가 5라고 가정
	Circle* whiteCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, whiteCircle);

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

// 복사 생성자를 사용하지 않고 Clone을 사용하는 이유가 무엇?
// => 견본 도형이 모두 Rect 라면 "복사 생성자"로 가능
// => 그런데, 견본으로 등록된 객체가 다양한 타입
// => 그래서 Clone 사용