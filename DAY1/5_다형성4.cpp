// 5_������4.cpp

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void go() { cout << "Animal go" << endl; }
};

class Dog : public Animal {
public:
	// 1. �θ��� �Լ��� �����Լ��̸�, �ڽ��� �������̵��� �Լ��� �����Լ��Դϴ�.

	// 2. override: C++11
	//   : �θ� �����ϴ� �Լ��� �������̵��� ������ ������ üũ �����մϴ�.
	//   : �ڽ� Ŭ������ �������ϴ� �Լ��� �ݵ�� �����Լ��̾�� �մϴ�.
	// virtual void go() override { cout << "Dog go" << endl; }
	void go() override { cout << "Dog go" << endl; }
};

int main()
{
	Animal* p = new Dog;
	p->go();
}
