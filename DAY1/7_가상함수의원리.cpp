#include <iostream>
using namespace std;

// 1. ���� �Լ��� ������ ��� ��ü�� ũ��� ������ ũ��(8����Ʈ)��ŭ �߰��˴ϴ�.
// 2. ���� �Լ� ���̺��� ����Ű�� �������Դϴ�.
// 3. ���� �Լ� ���
//   1) ��ü�� ũ�Ⱑ ������ ũ�⸸ŭ �����մϴ�. (�����Լ� ���̺� ������)
//   2) ���� �Լ� ���̺� ũ��� ���� �Լ��� ������ ���� �����˴ϴ�.
//      "�����Լ��� ����" * "��� �Լ� ������" * Ÿ��

class Animal {
	int age;
	int color;
public:
	virtual void go() {}
	virtual void foo() {}
};

class Dog : public Animal {
	int gender;
public:
	void go() override {}
};

int main()
{
	cout << sizeof(Animal) << endl; // 8 -> 16

	Animal* p = new Dog;
	p->go();  // (p->vptr)[0]();

	p->foo(); // (p->vptr)[1]();
}