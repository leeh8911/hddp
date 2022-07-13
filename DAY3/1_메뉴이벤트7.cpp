#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::bind, std::function
using namespace std::placeholders; //

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

class MenuItem : public BaseMenu
{
	int id;
//	void(*handler)(); // �Ϲ� �Լ� �ۿ� ����Ҽ� �����ϴ�

	// typedef std::function<void()> HANDLER;
	using HANDLER = std::function<void()>; 

	std::vector< HANDLER > v;

public:
	MenuItem(const std::string& s, int n, HANDLER h = nullptr) 
		: BaseMenu(s), id(n) 
	{
		if (h != nullptr)
			v.push_back(h); 
	}
	// ������ ���ڷε� �ڵ鷯 ��ϰ����ϰ� �Ʒ� �Լ��� ȣ���ص� ��ϰ���
	void add_handler(HANDLER f) { v.push_back(f); }

	void command()
	{
		// �޴� ���ý� ��ϵ� ��� �Լ����� �˷��ݴϴ�.
		// ������(Observer)���� : �ѳ��� ��ü�� ��ȭ�� �������� ����
		for (HANDLER f : v)
			f(); 		
	}
};
//------------------
void f0()       { std::cout << "f0" << std::endl; }
void f1(int id) { std::cout << "f1 : " << id << std::endl; }

class Dialog
{
public:
	void close() { std::cout << "dialog close" << std::endl; }
};
//--------------------------------------------------------
int main()
{
	PopupMenu* root = new PopupMenu("root");

	root->add_menu(new MenuItem("HD", 11, &f0));
	root->add_menu(new MenuItem("FHD", 12, std::bind(&f1, 12)));
	root->add_menu(new MenuItem("UHD", 13, std::bind(&f1, 13)));

	Dialog dlg;
	root->add_menu(new MenuItem("8K", 14, 
							std::bind(&Dialog::close, &dlg)));



	root->command();

	delete root;
}




