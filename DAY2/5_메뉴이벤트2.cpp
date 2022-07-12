// 3_�޴�7

#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;
};



class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	~PopupMenu()
	{
		for (auto p : v)
			delete p;
	}




	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". ����" << std::endl;
			std::cout << "�޴� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;
			v[cmd - 1]->command();
		}
	}
};
//=============================================
// ��� 1. ���ϴ� ���� �����Լ���...
// => ������ ���������.. 
// => �޴������� �����ϸ� �Ļ�Ŭ������ ������ �ʹ� ��������.
// => �޴��� 50����� "MenuItem"�� �Ļ� Ŭ������ 50�� �ʿ�

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		doCommand();
	}
	virtual void doCommand() {}
};

class HDMenu : public MenuItem
{
public:
	// C++11 ������ �ڵ� ��Ÿ��
//	HDMenu(const std::string& s, int n) : MenuItem(s, n) {}
	
	// C++11 ���ʹ� "������ ���" ���� ���
	using MenuItem::MenuItem; // �� �ڵ尡 ���� ������ ȿ��

	void doCommand() override 
	{ 
		std::cout << "change HD" << std::endl; 
		_getch();
	}
};
class FHDMenu : public MenuItem
{
public:
	using MenuItem::MenuItem;
	void doCommand() override
	{
		std::cout << "change FHD" << std::endl;
		_getch();
	}
};
int main()
{
	PopupMenu* root = new PopupMenu("root");

	root->add_menu(new HDMenu("HD", 11));
	root->add_menu(new FHDMenu("FHD", 12));

	root->command();

	delete root;
}




