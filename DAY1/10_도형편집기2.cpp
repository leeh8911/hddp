// 10_����������2.cpp

#include <iostream>
#include <vector>
using namespace std;

// �䱸����: Draw ����� ��Ƽ �����忡�� �����ϰ� ����ȭ�Ǿ�� �մϴ�.
#include <mutex>

// mutex m;
class Mutex {
public:
	void lock() { cout << "Mutex lock" << endl; }
	void unlock() { cout << "Mutex unlock" << endl; }
};

Mutex m;

// "���뼺�� �������� �и�" ���� ��Ģ
// : ���ϴ� �Ͱ� ������ �ʴ� ���� �и��ؾ� �մϴ�.
//  => ��� �Լ����� �и��ϴ� ���
//   - ������ �ʴ� ���� �Ϲ� �Լ��� �ΰ�, ���ϴ� ���� ���� �Լ��� �̾Ƴ��ϴ�.
//   : Template Method Pattern, NVI(Non Virtual Interface)
//    ������ �ʴ� ��ü �˰����� �θ� �񰡻��Լ��� ���� �����ϰ�,
//    ���ϴ� �κи� �����Լ�ȭ�ؼ� �ڽ��� ������ �� �ֵ��� �ϴ� ���� ���.

class Shape {
public:
	virtual ~Shape() {}

	void Draw() { 
		//m.lock();
		DrawImpl();
		//m.unlock();
	}

	virtual void DrawImpl()
	{
		cout << "Shape Draw" << endl;
	}

	virtual Shape* Clone() = 0;

};

class Rect : public Shape {
public:
	void DrawImpl() override {
		cout << "Rect Draw" << endl; 
	}

	// ���� ��ȯ�� ��Ģ
	// : �θ� ��� �Լ��� ��ȯ���� ���� Ŭ������ �����ϴ� ���� ����մϴ�.
	//  => ���ø�
	Rect* Clone() override { return new Rect(*this); }
};

class Circle : public Shape {
public:
	void DrawImpl() override { 
		cout << "Circle Draw" << endl; 
	}

	Circle* Clone() override { return new Circle(*this); }

};

class Triangle : public Shape {
public:
	void DrawImpl() override {
		cout << "Triangle Draw" << endl;
	}

	Triangle* Clone() override { return new Triangle(*this); }

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
		else if (cmd == 3) shapes.push_back(new Triangle);

		// ������ �����ϰ� �ͽ��ϴ�.
		else if (cmd == 8) {
			int index;
			cin >> index;

			shapes.push_back(shapes[index]->Clone());
			// Replace type code with polymorphism


			// Rect? Circle?
			//  => �Ʒ� ó�� ������ ��� ���ο� ������ �߰��� ������,
			//     �ڵ�� ����Ǿ�� �մϴ�.
#if 0
			if (typeid(*shapes[index]) == typeid(Rect)) {
				shapes.push_back(new Rect(*static_cast<Rect*>(shapes[index])));
			}
			else if (typeid(*shapes[index]) == typeid(Circle)) {
				shapes.push_back(new Circle(*static_cast<Circle*>(shapes[index])));
			}
#endif
		}

		else if (cmd == 9) {
			// �������� OCP�� �����մϴ�.
			// "���ο� ����� �߰��Ǿ ���� �ڵ带 ������ �ʿ䰡 �����ϴ�."
			for (Shape* p : shapes)
				p->Draw();
		}
	}

}