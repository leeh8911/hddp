// 9_�߻�Ŭ����2.cpp
#include <iostream>
using namespace std;

class Camera {
public:
	void StartRecording() { cout << "Start Recording" << endl; }
	void StopRecording() { cout << "Stop Recording" << endl; }
};



class HDCamera {
public:
	void StartRecording() { cout << "Start Recording" << endl; }
	void StopRecording() { cout << "Stop Recording" << endl; }
};

// 1. Car Ŭ������ Camera Ŭ������ ���� ������ �����Ǿ� �ֽ��ϴ�.
//  "���� ����": �����ϴ� Ŭ������ ��ü���� Ÿ���� ����մϴ�.
//  "���� ���� / ������ ����": �����ϴ� Ŭ������ ��ü���� Ÿ���� �ƴ϶� �߻� Ÿ���� ����մϴ�.

class Car {
	HDCamera* camera;
public:
	Car(HDCamera* p) : camera(p) {}

	void Go()
	{
		camera->StartRecording();

		camera->StopRecording();
	}
};

int main()
{
	HDCamera camera;
	Car car(&camera);

	car.Go();
}