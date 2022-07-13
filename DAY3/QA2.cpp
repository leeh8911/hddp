#include <iostream>

class Shape
{
	int data;
};

class X
{
	int x;
};

class C1 : public Shape, public X 
{
	int c1;
};
class C2 : public X, public Shape
{
	int c2;
};
int main()
{
	// ���� ����� ������ ������ 
	// C++, python : ����
	// C#, java    : ���� ����(�� �������̽��� ��� ���� ��Ӱ���)
	C1 c1;
	C2 c2;
	Shape* p1 = &c1;
//	Shape* p2 = &c2; // (char*)&c2 + sizeof(1��°��� Ŭ���� X);

	// ��Ӱ��� ���� ���� ����, ������ &c2 �ּҸ� Shape* �� ��ڴٴ� �ǵ�
	// ��������ȯ(reinterpret - �ٽ� �ؼ��ϰڴ�)
	Shape* p2 = reinterpret_cast<Shape*>(&c2);

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;

}