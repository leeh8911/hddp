// 9_�߻�Ŭ����4.cpp
#include <iostream>
using namespace std;

// �������̽� ������
// : ��ȭ�� �����ϱ� ��ƽ��ϴ�.
struct MP3 {
	virtual ~MP3() {}

	virtual void Play() = 0;
	virtual void Stop() = 0;

	// �������̽�: �⺻ ������ ��������.
	virtual void PlayOneMinute()
	{
		Play();
		// 1����
		Stop();
	}
};

class Person {
public:
	void PlayMusic(MP3* p) {
		// p->Play();
		p->PlayOneMinute();
		p->Stop();
	}


};

class Android : public MP3 {
public:
	void Play() override { cout << "Play Music" << endl; }
	void Stop() override { cout << "Stop Music" << endl; }
};

class Apple : public MP3 {
public:
	void Play() override { cout << "Play Music" << endl; }
	void Stop() override { cout << "Stop Music" << endl; }
};

int main()
{
	Person person;
	Apple apple;
	Android android;

	person.PlayMusic(&android);
	person.PlayMusic(&apple);
}