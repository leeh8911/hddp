// 1_thiscall4.cpp
#include <Windows.h>

#include <iostream>
using namespace std;

class Thread {
public:
	void run() {
		CreateThread(0, 0, &foo, this, 0, 0);
	}

	// 1. �Ϲ� �Լ� �����͸� ���� ���� ��� �Լ��� ������ �� �ֽ��ϴ�.
	static DWORD __stdcall foo(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// 2. ���� ��� �Լ��ȿ��� �Ϲ� ��� �Լ��� ȣ���� �Ұ����մϴ�.
		// : this�� ��������� �����մϴ�.
		self->threadLoop();
		return 0;
	}

	virtual bool threadLoop() { return false; }
};

//----------------------
class MyThread : public Thread {
public:
	virtual bool threadLoop()
	{
		cout << "MyThread threadLoop" << endl;
		return true;
	}
};


int main()
{
	MyThread t;
	t.run();   // �� ���� �����尡 �����Ǿ �����Լ��� threadLoop()�� ȣ���ؾ� �մϴ�.

	getchar();
}

#if 0
DWORD __stdcall foo(void* p)
{
	while (1) {
		cout << "foo thread" << endl;
		Sleep(1000);
	}
	
	return 0;
}

int main()
{
	CreateThread(0, 0, &foo, 0, 0, 0);
	while (1) {
		cout << "main thread" << endl;
		Sleep(500);
	}
	
}
#endif