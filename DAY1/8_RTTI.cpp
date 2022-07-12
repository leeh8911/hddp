// 8_RTTI.cpp
#include <iostream>
#include <string>
using namespace std;

// RTTI(Run Time Type Information)
//  : type_info ����ü�� ���� �Լ� ���̺� ����˴ϴ�.
// 
// 1. type_info ����ü
// 2. typeid ������
//   1) Ÿ��
//   2) ��ü

class Animal {
public:
	 virtual ~Animal() {}
};

class Dog : public Animal {
public:
	int age = 10;
};

class Cat : public Animal {
public:
	string name = "Cat";
};

#if 0
int main()
{
	Animal* p = new Cat; //new Dog;

	// ���� �Լ� ���̺��� ������ ����� �� �����ϴ�.
	Cat* p2 = dynamic_cast<Cat*>(p);
	cout << p2 << endl;
	if (p2) {
		cout << p2->name << endl;
	}


}
#endif

#if 0
int main()
{
	Animal* p = new Cat;

	// p�� Dog���
	const type_info& t1 = typeid(Dog);  // Ŭ����
	const type_info& t2 = typeid(*p);   // ��ü

	cout << t2.name() << endl;

	if (t1 == t2)
	{
		cout << "Dog Ÿ���Դϴ�.." << endl;
		Dog* p2 = static_cast<Dog*>(p);
		cout << p2->age << endl;
	}
	else if (typeid(*p) == typeid(Cat))
	{
		cout << "Cat Ÿ���Դϴ�.." << endl;

		Cat* p3 = static_cast<Cat*>(p);
		cout << p3->name << endl;
	}

	



}
#endif