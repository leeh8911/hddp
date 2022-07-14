// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}

	// ��Ģ 2. ���� �����ڿ� ���Կ����ڵ� "�����Ϸ��� �ڵ������Ҽ� ���� �Ѵ�"
	
	// C++98 ���� ��� 
	// => ����ڰ� "private ������ ����" �����.
	// 1. ����ڰ� ���������Ƿ� �����Ϸ��� ��������
	// 2. ���� �����ڸ� ����ϴ� �ڵ尡 ������ ���� ����
	// 3. ���� �����ڸ� ����ϴ� �ڵ尡 ������ ��ũ���� - �ᱹ ����ɼ� ���ٴ��ǹ�
//private:
//	Cursor(const Cursor& c);
//	Cursor& operator=(const Cursor&);

	// C++11 ����
	// �ᱹ �� ����� �ǵ��� "�����Ϸ��� ���� �����ڸ� ������ ���ϰ�" �Ϸ��� �ǵ�
	// C++11 ���ʹ� �Լ� ���� ���� ���
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
				// ���� �����ڸ� ���� �ϸ� ���������� ���Կ����ڵ� ���� �մϴ�.


	// ��Ģ 3. ���� �Ѱ��� ��ü�� �����ؼ� ��ȯ�ϴ� "static ��� �Լ�"
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	Cursor c3 = c1; // "���������" ȣ��..
					// �̷��� ����� �͵� �Ҽ� ���� �ؾ� �մϴ�.


//	Cursor c1, c2;
}








