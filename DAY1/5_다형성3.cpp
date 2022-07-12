// 5_������3.cpp
#include <iostream>
using namespace std;

class Animal {
public:
	virtual void go() { cout << "Animal go" << endl; } // 1
};

class Dog : public Animal {
public:
	// �θ� �����ϴ� ��� �Լ��� �ڽ� Ŭ������ �������� �� �ֽ��ϴ�.
	// : �Լ� �������̵�
	virtual void go()
	{
		cout << "Dog go" << endl; // 2
	}
};

// Animal* p = ...;
// p->go();
// => �Լ� ���ε�
//   : � �Լ��� ȣ������ �����ϴ� ��

// 1) ���� ���ε�(static binding)
//  : �����Ϸ��� p�� Ÿ���� ����, ������ Ÿ�ӿ� �����ϴ� ��
//  => �����Ϸ��� �����ϱ� ������, �ζ���ȭ�� �����ϱ� ������ �����ϴ�.
// 
// 2) ���� ���ε�(dynamic binding)
//  : �����Ϸ��� p�� ����ð��� � ������ Ÿ���� ������ �ִ��� �����ϴ� �ڵ带 �����ϰ�,
//    ����ð��� ������ Ÿ�Կ� ����ؼ� �Լ��� ȣ���ϴ� ��
//  => �ζ���ȭ�� �Ұ����ϱ� ������, ��������� ȣ���� �����ϴ�.

int main()
{
	Animal a; Dog d;
	Animal* p = &a;
	p->go();

	p = &d;
	p->go();
}


#if 0
int main()
{
	Animal a;
	a.go();   // 1

	Dog d;
	d.go();   // 2
}
#endif