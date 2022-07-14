#include <iostream>
#include <vector>
#include <map>
#include "helper.h"


// 이 코드에서 배울 기술들
// 1. Rect::Create() 함수
//	=> new Rect; 이렇게 만들면 "클래스이름"이 필요함
//					클래스 이름을 자료 구조에 보관할 수 있음
//					그론데, 문자열로 객체 생성이 안됨
//					string s = "Rect";
//					s로 객체 생성 할 수 없음...

// auto f = Rect::Create;
// f()	이렇게 만드려면 함수 주소 필요
//		함수 주소는 자료구조 보관 가능하고
//		보관된 주소로 객체 생성 가능

// 2. 생성자 vs static 생성자 (C#의 개념)
// Rect r1;
// Rect r2; // 생성자 호출.. 객체당 한번씩 호출됨. 객체 초기화

// Rect::ar // Rect 클래스에 대해 최초에 1회 호출
//			// Rect 클래스 자체의 초기화에 활용 가능
//			// C++에는 없지만 C#에 있는 static 생성자 개념
//			// C++에서는 아래와 같은 static 멤버 데이터로 유사하게 구현

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

// 현재 모슨 시스템에서 사용되는 도형 클래스는 반드시 지켜야 하는 규칙이 생김
// 규칙 코드를 자동생성하는 매크로를 제공
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

// 번호 관리 측면에서 숫자는 한 곳에서 등록되는게 편리하지 않나?
// => 좋은 의견, 공장에게 도형 번호를 요청할 수 있다면.. 
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