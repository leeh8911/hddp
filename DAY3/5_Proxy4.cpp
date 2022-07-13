#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class CalcProxy : public ICalc
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


// �� CalcProxy Ŭ������ ���� �����ϴ� �ɱ�� ?

// 1. Ŭ���̾�Ʈ ������
// 2. ���� ������ => ����
// Proxy �� ���� �����ڰ� �ۼ��ؼ�
// Ŭ���̾�Ʈ �����ڵ鿡�� ���� �ϴ� ���Դϴ�.

int main()
{
	// �Ʒ� �ڵ�ó�� Ŭ���̾�Ʈ���� proxy �̸��� �ٷ� ����ϸ�
	// "���Ѱ���(tightly coupling)" �Դϴ�.
	// ���ο� proxy �� ������ client �ڵ尡 �����Ǿ�� �մϴ�.
	// CalcProxy* pCalc = new CalcProxy;

	// proxy �����, �ڵ������ �������� ���Ѱ���(loosely coupling)
	// �� �Ǿ�� �մϴ�.
	// ��, �������̽� ������� ����ؾ� �մϴ�

	ICalc* pCalc = new ? ;



	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





