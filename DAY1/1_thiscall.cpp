// 1_thiscall.cpp

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	// void set(Point* const this, int a, int b)
	void set(int a, int b)
	{	
		// int c = a + b;

		x = a;  // this->x = a;
		y = b;  // this->y = b;
	}	

	// ���� ��� �Լ�: ��ü�� �������� �ʾƵ� ȣ���� �����մϴ�.
	//   - this�� ���޵��� �ʽ��ϴ�.
	static void foo(int a)
	{
		// x = a;   // this->x = a; �� �Ǿ�� �ϴµ�, this�� �����ϴ�.
	}
};

int main()
{
	Point p1, p2;

	p1.set(10, 20);  // Point::set(&p1, 10, 20)
	p2.set(30, 40);  // Point::set(&p2, 10, 20)



}