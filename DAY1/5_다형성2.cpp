// 5_������2.cpp
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
	int getAge() const { return 10; }
};

class Dog : public Animal {};
class Cat : public Animal {};

// 1. ������ ó���ϴ� �Լ��� ���� �� �ֽ��ϴ�.
int GetAge(Animal* p)
{
	return p->getAge();
}

int main()
{
	vector<Dog*> dogs;
	vector<Cat*> cats;

	// 2. ������ �����ϴ� �����̳ʸ� ����� �� �ֽ��ϴ�.
	vector<Animal*> animals;


	Dog d; Cat c;
	cout << GetAge(&d) << endl;
	cout << GetAge(&c) << endl;
}




#if 0
class Dog {
public:
	int getAge() const { return 10; }
};

class Cat {
public:
	int getAge() const { return 20; }
};

int GetAge(Dog* p)
{
	return p->getAge();
}

int GetAge(Cat* p)
{
	return p->getAge();
}
#endif