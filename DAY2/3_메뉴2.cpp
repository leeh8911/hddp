#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// �޴� �׸� �Ѱ��� �����ϴ� Ŭ����
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title; }

	// �޴��� �����Ҷ� ȣ��Ǵ� �Լ�
	void command()
	{
		std::cout << get_title() << " �޴� ����" << std::endl;
		_getch();
	}
};

int main()
{
	// �ٽ� : �޴� �׸� �ϳ��� "��ü" �Դϴ�.
	//		 �޴� �׸��� 20�� ��� 20���� ��ü�� �����ϸ� �˴ϴ�.
	//	     �޴��� ����(����)�ǰ� �Ϸ��� command()�� ȣ���ϸ� �˴ϴ�.
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);
	m1.command(); // ��� ����
}




