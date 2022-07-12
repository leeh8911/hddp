// 10_����������.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. ��� ������ Ÿ��ȭ�ϸ� ���մϴ�.
// 2. ��� ������ ������ �θ� �ִٸ�, ��� ������ ��� ������ �� �ֽ��ϴ�.
//   "������ �����ϴ� �����̳�" => Upcasting

// 3. ��� �ڽ��� ������ Ư¡�� �ִٸ�, �ݵ�� �θ𿡵� �־�� �մϴ�.
//    �׷��� �θ� �����ͷ� ��� ����� �� �ش� Ư¡�� �̿��� �� �ֽ��ϴ�.
//    : LSP(Liskov Substitution Principle) 
//    => �ڽ��� ������ ����� �ݵ�� �θ�κ��� ��ԵǾ�� �Ѵ�.

// 4. �θ��� �Լ��� �ڽ��� �������ϴ� ��� �Լ��� �ݵ�� �����Լ� �̾�� �մϴ�.
//    "���� �Լ��� �ƴ� �Լ��� ���������� ����" => Effective C++ �ݾ�

// 5. �θ� Ŭ������ �ݵ�� ���� �Ҹ��ڸ� �����ؾ� �մϴ�.

class Shape {
public:
	virtual ~Shape() {}

	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape {
public:
	void Draw() override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape {
public:
	void Draw() override { cout << "Circle Draw" << endl; }
};

int main()
{
	// vector<Rect*> rects;
	// vector<Circle*> circles;

	vector<Shape*> shapes;
	int cmd;

	while (1)
	{
		cin >> cmd;

		if (cmd == 1) shapes.push_back(new Rect);
		else if (cmd == 2) shapes.push_back(new Circle);

		else if (cmd == 9) {
			for (Shape* p : shapes)
				p->Draw();
		}
	}

}