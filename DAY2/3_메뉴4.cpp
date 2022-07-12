#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ���հ�ü(PopupMenu)�� ������ü(MenuItem, leaf)
// �� �ƴ϶� ���հ�ü �ڽŵ� �����Ѵ�.
// => ���հ�ü�� ������ü�� ������ ��� Ŭ������ �ʿ� �ϴ�.

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {} // ��� Ŭ������ �Ҹ��ڴ� �׻� ���� �Լ� �̾�� �Ѵ�.

	std::string get_title() const { return title; }
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << get_title() << " �޴� ����" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls"); // ȭ�� �����

			int sz = v.size(); // ���� �޴� ����

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". ����" << std::endl;
			std::cout << "�޴� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) // ���� �޴� ����
				break;  // �Ǵ� return

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			// ���õ� �޴��� �����մϴ�.
			// MenuItem ���ý� "command()"�� ȣ���ϱ�� ��ӵǾ� �־����ϴ�.
			v[cmd - 1]->command();

		}



	}
};






int main()
{
	MenuItem m1("��ġ���",   11);
	MenuItem m2("�Ұ����", 12);

	PopupMenu kimbam("����");
	kimbam.add_menu(&m1);
	kimbam.add_menu(&m2);


	MenuItem m3("���", 21);
	MenuItem m4("�쵿", 31);

	PopupMenu pm("������ �޴�");
	pm.add_menu(&kimbam); // �ٽ�.. �� ������ ������..
	pm.add_menu(&m3);
	pm.add_menu(&m4);

	pm.command(); // �˾� �޴��� �����Ҷ� 
				  // �ؾ� ������ �����غ�����.

}




