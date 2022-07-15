#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std;
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function< void(void*) >;

	std::map<std::string, std::vector<HANDLER> > notif_map; // �� �ڷᱸ���� �ٽ� �Դϴ�.
public:
	void addObserver(std::string key, HANDLER handler)
	{
		notif_map[key].push_back(handler);
	}

	void postNotificationWithName(std::string key, void* hint)
	{
		std::vector<HANDLER>& v = notif_map[key];
		// ��ϵ� ��� �Լ� ȣ��
		for (auto f : v)
			f(hint);
	}

	// global �뺸���Ͷ�� ������ ����� ���ô�.
	// ����ȭ �Ҷ� "global �뺸���͸� �������� defaultCenter() �Լ��� ȣ���ض�" ��� ����ȭ �մϴ�.
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter nc;
		return nc;
	}
};
//----------------------------------------------
void foo(void* p)        { cout << "foo : " << (int)p << endl; }
void goo(void* p, int a) { cout << "goo : " << (int)p << endl; }

int main()
{
	// �Ʒ� ó�� ����ڰ� ���� �ǰ�(Local �뺸����)
	NotificationCenter nc;

	// �Ʒ� ó�� ���� �Ѱ��� �����ϴ� global �뺸���� �� ������ �ְ� �սô�.
	NotificationCenter& center = NotificationCenter::defaultCenter();

	// ���� ����.
//	nc.addObserver("LOWBATTERY", &foo, NEWTHREAD );

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0) );

	nc.addObserver("LOWBATTERY", [](void* p) { std::cout << "lambda " << reinterpret_cast<long long>(p) << std::endl; } );

	nc.addObserver("DISCONECT_WIFI", &foo);


	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}

// ���� ���� ����
// Composite ����
// Chain Of Responsibility : å���� ����

// ���� : template method, strategy, prototype, adapter
// 
// ���� : ������, proxy, facade, bridge, adapter, decorator...  

