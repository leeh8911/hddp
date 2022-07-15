#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// �ٽ� 
// list      : ��� ��Ұ� ������ Ÿ���Դϴ�.
//			   => �׷��� visit(T& v) ó�� �Լ��� �Ѱ��� �˴ϴ�.
// 
// PopupMenu : ����� Ÿ���� �ٸ��ϴ�.

class MenuItem;
class PopupMenu;  // Ŭ���� ���� ����

struct IMenuVisitor
{
	virtual void visit(MenuItem* mi) = 0;
	virtual void visit(PopupMenu* pm) = 0;

	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void Accept(IMenuVisitor* visitor) = 0;
	virtual ~IAcceptor() {}
};

class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}

	void Accept(IMenuVisitor* visitor) override
	{
		// MenuItem �� �ٸ� �޴��� �������� �ʴ´�.
		// �׳� �ڽŸ� �湮�ڿ� ����
		visitor->visit(this); 
	}
};




class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	void Accept(IMenuVisitor* visitor) override
	{
		// ���� ������
		visitor->visit(this);

		// �湮�ڸ� �ٽ� ���� ���� ��� ��ҿ� �湮 ��Ų��.
		for (auto& e : v)
		{
			e->Accept(visitor); 
		}
	}




	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
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

			int cmd;
			std::cout << "�޴��� �����ϼ��� >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};


// ���� "�޴� �Ѱ��� ���� ����"�� ������ �湮�ڵ��� ���� ����ϸ� �˴ϴ�.

class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	void visit(MenuItem* mi) {}  // �޴������� �湮�� ������ ����.

	void visit(PopupMenu* pm) 
	{
		std::string s = "[ " + pm->get_title() + " ]";

		pm->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	PopupMenuTitleChangeVisitor v; // �˾��޴��� Ÿ��Ʋ�� �����ϴ� �湮��

	root->Accept(&v);


	root->command();

}




