// 4_�����ڼҸ���2.cpp
#include <iostream>

class Animal
{
// public:
protected:
	Animal(int age) {}
};

class Dog : public Animal {
public:
	Dog(int age) : Animal(age) {}

	Dog() : Animal(0) {}
};

// protected ������ �ǵ�: �ڽ��� ���� �� ������(�߻��� ����),
//                       �ڽ� Ŭ������ ���� �� �ְ� �ϰ� �ʹ�.
//  MFC: CObject / Android: RefBase

int main()
{
	// Animal a(10);
	Dog b(20);
}