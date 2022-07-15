// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// Bridge ����
// => ������ �߻�(������, ����ڰ� ����ϴ� ����) �� �и��Ͽ�
//    ��ȣ ������ update �� �����ϰ� �Ѵ�.

// ��ȭ�� ��û�� ���ٸ�, ������ �ø��� �ذ�ȴٴ� �ǵ�!


// MP3 ����� �������̽�
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;

	virtual ~IMP3() {}
};

class IPod : public IMP3	// ������ ������
{
public:
	void Play() { cout << "Play MP3 with IPod" << endl; }
	void Stop() { cout << "Stop" << endl; }
};

// People�� IMP3 �� ���� ����ϰ� ��������
// ������(�߻���, ��������忡���� interface)�� �����Ѵ�.

class MP3
{
	IMP3* impl; // ���� ������ ����Ű�� ������
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr)
			impl = new IPod;
	}
	void Play() { impl->Play(); }
	void Stop() { impl->Stop(); }
	void PlayOneMinute()
	{
		impl->Play();
		// 1�еڿ�
		impl->Stop();
	}
};

class People
{
public:
	// ����ڴ� ���������� �ٷ� ������� ����
	// ������(�߻���)�� ���
	void Use(MP3* p)
	{
		p->Play();
		p->Stop();

		// �׷���. �䱸������ ���� ����/�߰��ȴ�.
		// 1�� �̸���� ����� ��û�Ѵ�.
		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	MP3 mp3;
	p.Use(&mp3);
}


