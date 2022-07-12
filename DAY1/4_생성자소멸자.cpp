// 4_�����ڼҸ���.cpp
#include <iostream>
using namespace std;

class Base {
public:
	// Base() { cout << "Base()" << endl; } => �⺻ ������
	Base(int) { cout << "Base(int)" << endl; }

	~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:

	// ��Ȯ�� ����: �ڽ��� �������� �պκ�(�ʱ�ȭ����Ʈ)�� �θ��� �����ڸ� ȣ���ϴ� ���� �ڵ带
	//            �����Ϸ��� �������ݴϴ�.
	//   > �θ� �⺻ �����ڸ� �������� ���� ���, ��������� �θ��� �����ڸ� ȣ���ؾ� �մϴ�.
	Derived() : Base(42)
	{ cout << "Derived()" << endl; }
	
	// �ڽ��� �Ҹ����� ������ �κп� �θ��� �Ҹ��ڸ� ȣ���ϴ� ���� �ڵ带 �����Ϸ��� �������ݴϴ�.
	~Derived() 
	{
		cout << "~Derived()" << endl;
		// Base::~Base()
	}
};

// Base()
// Derived()
// ~Derived()
// ~Base()

int main()
{
	Derived d;
	// Deribed::Derived()
}