// 6_����Ҹ���.cpp

#include <iostream>
using namespace std;

class Animal {
public:
	Animal() { cout << "Animal()" << endl; }
	virtual ~Animal() { cout << "~Animal()" << endl; }
};
// �θ� Ŭ������ �ݵ�� ���� �Ҹ��ڰ� �����Ǿ�� �մϴ�.

class Dog : public Animal {
public:
	Dog() { cout << "Dog()" << endl; }
	virtual ~Dog() { cout << "~Dog()" << endl; }
	// ~Dog() override { cout << "~Dog()" << endl; }
};

// 1. �θ��� �����͸� ���� �ڽ��� �Ҹ��ڰ� ����� ȣ����� �ʴ� ������ �߻��մϴ�.
//   > �Ҹ��ڰ� ���� ���ε��� �ϱ� ������ �߻��ϴ� �̽� �Դϴ�.
// 2. �Ҹ��ڵ� ���� ���ε� ������� ȣ��Ǿ�� �մϴ�.
//   > ���� �Ҹ���
// 3. �θ��� �Ҹ��ڰ� �����̸�, �ڽ��� �Ҹ��ڵ� �����Դϴ�.

#include <memory>

int main()
{
	Animal* p2 = new Dog;

	shared_ptr<Animal> p(p2);

	// Dog d;
	// Animal* p = new Dog;

	// delete p;
	// Animal::~Animal()
}