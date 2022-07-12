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
// ��� 2. ���ϴ� ���� �ٸ� Ŭ������

// �޴� �̺�Ʈ�� ó���ϰ� ���� Ŭ������ �ݵ�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IMenuListener
{
	virtual void command() = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int id;

	IMenuListener* pListener = nullptr;
public:
	void setListener(IMenuListener* p) { pListener = p; }

	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		// �޴��� ���õǾ����� "��ϵ� �����ʰ�ü"���� �˷��ش�.(��ӵ� �Լ� ȣ��)
		if (pListener)
			pListener->command();
	}
};
//======================
// ���� ����ڰ� ����� Ŭ������ �޴��� ó���ϰ� �ʹٸ� 
// IMenuListener �������̽��� �����ؾ� �մϴ�.
class Camera : public IMenuListener
{
public:
	void command() override
	{
		std::cout << "Camera command" << std::endl;
		_getch();
	}
};

int main()
{
	Camera* camera = new Camera;
	PopupMenu* root = new PopupMenu("root");

	MenuItem* p1 = new MenuItem("hd", 11);
	MenuItem* p2 = new MenuItem("fhd", 12);

	// �� �޴��� �̺�Ʈ�� ó���� ��ü�� ����մϴ�.
	p1->setListener(camera);
	p2->setListener(camera);

	root->add_menu(p1);
	root->add_menu(p2);
	
	root->command();

	delete root;
}




