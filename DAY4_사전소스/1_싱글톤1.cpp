// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
// => ���� �Ѱ��� ��ü�� ����
// => ��𼭵� ������ ������� ��ü�� ���� (Cursor::getInstance())

// �̱��� ���Ͽ� ���� ���� ���� �ü� : 
// => �ᱹ ���� ����!!!! (���� ������ ���� ����)

// �̱����� �����ϴ� ����� ���� �پ���!
// �Ʒ� ó�� "static ���� ����"�� ���� �ϴ� ���
// => effective-C++ �� ������ "scott-meyer"�� ó������ ����
// => "Meyer's Singleton"
class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}
	// ��Ģ 2. ���� �����ڿ� ���� �����ڵ� "�����Ϸ��� �ڵ����� ������ �� ���� �ؾ� ��"
	// C++98 ����
	// => ����ڰ� "private ����"�� "����" �����
	// 1. ����ڰ� ���������Ƿ� �����Ϸ��� ���� ����.
	// 2. ���� �����ڸ� ����ϴ� �ڵ尡 ������ ���� ����
	// 3. ���� �����ڸ� ����ϴ� �ڵ尡 ������ "��ũ ����" - �ᱹ ����� �� ����
//private:
//	Cursor(const Cursor& c);
//	Cursor& operator=(const Cursor& c);

	// C++11 ����
	// �� ����� �ǵ��� "�����Ϸ��� ���� �����ڸ� ������ ���ϰ�" �Ϸ��� �ǵ�
	// C++11 ���ʹ� �Լ� ���� ���� ���
private:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
	// ���� �����ڸ� �����ϸ�, ���������� ���� �����ڵ� ������
	
	// ��Ģ 3. ���� �Ѱ��� ��ü�� �����ؼ� ��ȯ�ϴ� "static ��� �Լ�"
public:
	static Cursor& getInstance() {
		static Cursor instance;
		return instance;
	}

};


int main()
{
	Cursor& c1 = Cursor::getInstance(), &c2 = Cursor::getInstance();

	std::cout << "C1 ��ü �ּ� : " << &c1 << std::endl;
	std::cout << "C2 ��ü �ּ� : " << &c2 << std::endl;

	// Cursor c3 = c1; // "���� ������" ȣ��
						// �̷��� ����� �͵� �� �� ���� �ؾ� ��
						// ���� �����ڸ� �����ϸ� Error!
}








