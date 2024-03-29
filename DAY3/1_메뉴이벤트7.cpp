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
			std::cout << sz + 1 << ". 종료" << std::endl;
			std::cout << "메뉴 선택하세요 >> ";

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
//	void(*handler)(); // 일반 함수 밖에 등록할수 없습니다

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
	// 생성자 인자로도 핸들러 등록가능하고 아래 함수를 호출해도 등록가능
	void add_handler(HANDLER f) { v.push_back(f); }

	void command()
	{
		// 메뉴 선택시 등록된 모든 함수에게 알려줍니다.
		// 관찰자(Observer)패턴 : 한나의 객체의 변화를 여러곳에 전달
		for (HANDLER f : v)
			f(); 		
	}
};
//------------------
void f0() { std::cout << "f0" << std::endl; _getch(); }
void f1(int id) { std::cout << "f1 : " << id << std::endl; _getch();}

class Dialog
{
public:
	void close() { std::cout << "dialog close" << std::endl; _getch();	}
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

	MenuItem* p = new MenuItem("16K", 15,
		[]() { std::cout << "lambda" << std::endl; _getch(); });

	root->add_menu(p);

	// 하나의 메뉴 아이템에 여러개 핸들러 등록 가능 ( vector<HANDLER> 로 만든 이유)
	p->add_handler(&f0);
	p->add_handler(std::bind(&f1, 15));


	root->command();

	delete root;
}

// effective C++ 격언 : bind 보다 람다표현식을 선호해라
//               "기존의 함수를 인자를 고정해서 사용하기 보다, 람다표현식으로 만들라는것"



