// 5_������.cpp
#include <iostream>
using namespace std;

class Animal {

};

class Dog : public Animal {

};

// 1. Upcasting
// 2. is-a
//     �ڽ� Ŭ���� is a �θ� Ŭ����
// 3. Upcasting�� public ��ӿ����� ���˴ϴ�.
int main()
{
	Animal a; Dog d;

	// �θ��� ������ Ÿ���� ���� �ڽ� ��ü�� �ּҸ� ���� �� �ֽ��ϴ�.
	Animal* p = &d;

	// �θ��� ������ Ÿ���� �ڽ��� ������ Ÿ�������� �Ϲ����� ��ȯ�� ������� �ʽ��ϴ�.
	// => ������� ĳ������ �ʿ��մϴ�.
	Dog* p2 = static_cast<Dog*>(p);
}