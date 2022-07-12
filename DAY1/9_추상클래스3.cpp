// 9_�߻�Ŭ����3.cpp
#include <iostream>
using namespace std;

// ��ü ���� 5�� ��Ģ
//  => SOLID
//  1) SRP(Single Reponsibility Principle)
//    - ���� å���� ��Ģ
// 
//  2) OCP(Open Close Principle)
//    - ���� ����� ��Ģ
// 
//  3) LSP(Liskov Substitution Principle)
//    - �������� ġȯ ��Ģ
//    : �ڽ��� ����� ����� �θ�κ��� ��ԵǾ�� �Ѵ�.
// 
//  4) ISP(Interface Segregation Principle)
//    - �������̽� �и� ��Ģ
//    : ���� �������̽����ٴ� ����ȭ�� �������̽��� ����.
// 
//  5) DIP(Dependency Inversion Principle)
//    - ���� ���� ���� ��Ģ
//    : Ŭ���̾�Ʈ�� ��ü���� Ÿ���� ���� �̿��ϴ� ���� �ƴ϶�
//      �߻� ���信 �����ؾ� �Ѵ�.

// 1. Camera
//    ī�޶� ����ڿ� ī�޶� ������ ������ ��Ģ�� ���� �����ؾ� �մϴ�.
//   => �������̽�, ��������
//   => ��ü ������ ������ ����!
//   => OCP(Open Close Principle, ���� ��� ��Ģ) �����մϴ�.
//    : Ȯ�忡�� ���� �־�� �ϰ�, �������� ���� �־�� �Ѵ�.
//     - "���ο� ����� �߰��Ǿ, ���� �ڵ�� �����Ǹ� �ȵȴ�" ��Ģ


struct ICamera {
	virtual ~ICamera() {}

	virtual void StartRecording() = 0;
	virtual void StopRecording() = 0;
};

// 2. ��¥ ī�޶�� �������� ������, ��Ģ��θ� ����ϸ� �˴ϴ�.
class Car {
	ICamera* camera;
public:
	Car(ICamera* p) : camera(p) {}

	void Go()
	{
		camera->StartRecording();

		camera->StopRecording();
	}
};

// 3. ��� ī�޶�� �ݵ�� ICamera�� �������̽��� �����ؾ� �մϴ�.
// "�������̽��� ����Ѵ� ��� �����ʰ� �������̽��� �����Ѵ�"��� �մϴ�.
class Camera : public ICamera {
public:
	void StartRecording() override
	{
		cout << "Start Recording" << endl;
	}

	void StopRecording() override
	{
		cout << "Stop Recording" << endl;
	}
};

class HDCamera : public ICamera {
public:
	void StartRecording() override
	{
		cout << "Start Recording" << endl;
	}

	void StopRecording() override
	{
		cout << "Stop Recording" << endl;
	}
};

int main()
{
	HDCamera camera;
	Car car(&camera);

	car.Go();
}
