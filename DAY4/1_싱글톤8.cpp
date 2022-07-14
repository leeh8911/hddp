#include <iostream>

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor()" << std::endl;
	}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance; // error. �� �ڵ�� ���� ����
	static Cursor instance;  // �� �ڵ�� ���� �ƴմϴ�.

public:
	static Cursor& getInstance()
	{
//		static Cursor instance; // �� �ڵ�� 
								// �� �Լ��� ó�� ����ɶ� �����ڰ� ȣ��˴ϴ�.
		return instance;
	}
};
Cursor Cursor::instance;

int main()
{
//	Cursor& c1 = Cursor::getInstance();
//	Cursor& c2 = Cursor::getInstance();

}









