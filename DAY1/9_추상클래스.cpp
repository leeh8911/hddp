// 9_�߻�Ŭ����.cpp
#include <iostream>
using namespace std;

// �߻� Ŭ����
//  : ���� ���� �Լ��� 1�� �̻� ������ �ִ� Ŭ����
//  > �ν��Ͻ�ȭ�� �Ұ����մϴ�.
class Animal {
public:
	virtual ~Animal() {}

	// �θ� ���忡���� ������ ������ �ʿ䰡 ����,
	// �ڽ� Ŭ������ �ݵ�� �������̵� �ؾ� �ϴ� �Լ��� 
	// "���� ���� �Լ�"�� �����ϴ�.
	virtual void cry() = 0;
};

// �θ� �����ϴ� ���� �����Լ��� ���������� ������, 
// �ڽ� Ŭ������ �߻� Ŭ�����Դϴ�.
class Dog : public Animal {
public:
	void cry() override {}
};

class Camera {
//	int age;
public:
	virtual ~Camera() {}

	virtual void Take() = 0;

//	int GetAge() const { return age; }
};

int main()
{
	// Animal a;
	Dog d;

}