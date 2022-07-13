// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 

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

// Client �����ڴ� "DLL�� �̸�"�� ������ DLL�ȿ� � Ŭ������ �ִ��� �˼� �����ϴ�.
// �׷��� "new Ŭ�����̸�"�� �Ҽ� �����ϴ�.
// DLL �ȿ� "��ӵ� �̸�"�� �Լ��� ����� �� �ȿ��� ��ü�� �����մϴ�
// DLL �� update �Ǿ "�ּ��� �� �Լ� �̸�" �� �ݵ�� ���Ѿ� �մϴ�.
extern "C" __declspec(dllexport)   // ������ DLL ���� �Լ� ����� �ʿ�
ICalc* CreateProxy()
{
	return new CalcProxy;
}

// �����ϴ� ��
// 1. visual studio �� C/C++ �����Ϸ��� �̸��� cl.exe �Դϴ�.
// 2. ���� ��ư�� ������ "visual studio ����"�� ã������..
//    => ������ ���� ������Ʈ(Develop Command prompt) �� �����ϼ���
// 3. ����Ǵ� â���� cl �̶�� �Է��� enter �غ�����

// 4. ���� �ҽ��� �ִ� ������ �̵� �ϼ���.
// ����̺� �̵� : D: �ϰ� enter
// �����̵�     : cd \   ��Ʈ��
//			    cd ���ϴ� ����

// cl CalcProxy.cpp /LD /link user32.lib kernel32.lib gdi32.lib

// /LD   : DLL�� �����ش޶�.
// /link : �ش� ���̺귯���� ��ũ�ش޶�(IPC�� ���� ��������API ���)

