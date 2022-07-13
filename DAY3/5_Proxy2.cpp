#define USING_GUI
#include "cppmaster.h"

// proxy ����    : ���� ��Ҹ� ����ϴ� �����ڸ� ����� ����
// remote proxy : ������ ������ ����ϴ� Ŭ����!

// proxy : �Լ� ȣ��(Add()) �� ����ڵ�(1)�� �����ؼ� ������ ����
// stub  : ������ ��� �ڵ带 �ٽ� �Լ�ȣ��� ����(������ handler �� stub)

// ����, "proxy-stub" ��� �̶�� ǥ���ϰ� �մϴ�.

// ������ ������ ��Ȱ�� ����� Ŭ������ ���� �մϴ�.
class CalcProxy
{
	int server_handle;
public:
	CalcProxy()
	{
		server_handle = ec_find_server("Calc");
	}
	int Add(int a, int b) { return ec_send_server(server_handle, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server_handle, 2, a, b); }
};

int main()
{
	CalcProxy* pCalc = new CalcProxy;

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





