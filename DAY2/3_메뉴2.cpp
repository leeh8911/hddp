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
	MenuItem(const std::string& s) : title(s) {}

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
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);
	m1.command(); // ��� ����
}




