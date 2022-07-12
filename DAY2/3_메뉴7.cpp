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


int main()
{
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	//	root->add_menu(pm2);
	pm1->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	// �޴��� �߰��Ϸ��� �Ʒ� ó�� ���ٸ� �߰��ϸ� �ȴ�.
	pm1->add_menu(new MenuItem("8K", 14));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	// ���� �����Ϸ��� ?
	root->command(); // �ֻ��� �޴��� ����


	// �� �ڵ�� ��� �޴� ��ü�� new�� ��������Ƿ� "delete"�� �ʿ� �մϴ�.
	// 
	// ��� 1. vector< std::shared_ptr<BaseMenu> > ó�� ����Ʈ ������ ���
	//		=> ���� �����ϴ�.
	
	// ��� 2. �ֻ��� �޴��� delete �ϰ�.. �������� 
	//		  PopupMenu �� �Ҹ��ڿ��� "�ڽ��� �����޴��� delete" �ϱ�� ���
	// => �� ��� ��� "�޴� ��ü"�� new �� ������ �Ѵٴ� ��Ģ�� ����� �Դϴ�.
	delete root;

	// C++ : ��ü ������ "����" �Ǵ� "��" �� ����� �ִ�.
	//      => �׷��� �׻� ȥ�� ������
	// .
	// C#, java, python : ��� ��ü�� new �� ����ٴ� "�Ѱ��� ���"
	//					�Դٰ�, ������ �ڵ�����
	//					�ʹ� ����.!!




	// �ٵ�.. �� new�� �ϳ��� ? �Ʒ� ó�� �׳� ���ÿ� ������
	{
//		MenuItem m("HD", 11); // ������ ������ �ֽ��ϴ�.
							  // ���� ����� ������ �ı� �˴ϴ�.

//		new MenuItem("HD", 11); // ������ �� ��ü�� 
								// ���� ���ﶧ ���� �޸𸮿� �����ֽ��ϴ�.
								// "���� ���� �ӽ��ϴ�."
	}

}




