#include <iostream>

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// �ڽ��� ���� ó���� �õ� �Ѵ�.
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	// ������ ó���ϴ� �Լ�
	virtual bool HandleRequest(int problem) = 0;
};

//--------------
class TenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem)
	{
		std::cout << "TenHandler Start" << std::endl;

		if (problem == 10)
		{
			std::cout << "TenHandler �� ó�� �Ϸ�" << std::endl;
			return true;
		}
		return false;
	}
};
class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem)
	{
		std::cout << "OddHandler Start" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "OddHandler �� ó�� �Ϸ�" << std::endl;
			return true;
		}
		return false;
	}
};
int main()
{
	TenHandler h1;
	OddHandler h2;
	h1.next = &h2;

	// ������ �߻��ϸ� 1��° ������ ����
//	h1.Handle(10); 
//	h1.Handle(11);
	h1.Handle(12);
}
// �� ������ "Chain Of Responsibility" �Դϴ�.



