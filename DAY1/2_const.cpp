// 2_const.cpp
#include <iostream>
using namespace std;

class Test {
private:
	int x_ = 10;
	int y_ = 20;

public:
	// �Ʒ� ��� �Լ��� ���ؼ� ������ ���� ������� �ʴ´ٴ� ���� �����մϴ�.
	// void print(const Test* const this)
	void print() const
	{
		// x,y �� const�� ��޵˴ϴ�.
		cout << this->x_ << ", " << this->y_ << endl;
	}

	void setX(int x)
	{
		// this->x_ = x;

	}


};

void foo(const Test* p)
{
	// const*�� ���� �������� ��쵵 ��� ��� �Լ��� ȣ���� �����մϴ�.
	p->print();
}

void foo(const Test& t)
{
	// const&�� ���� ������ ��쵵 ��� ��� �Լ��� ȣ���� �����մϴ�.
	t.print();
}

int main()
{
	Test t1;
	t1.print();

	// ��� ��ü�� ��� ��� �Լ��� ȣ���� �����մϴ�.
	const Test t2;
	t2.print();
}