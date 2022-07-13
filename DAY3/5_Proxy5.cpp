#define USING_GUI
#include "cppmaster.h"

// ���� Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �����ø� �˴ϴ�.

// ICalc.h       : �������̽��� ��� ��� ����
// CalcProxy.dll : Proxy �ڵ尡 �ִ� DLL 

#include "ICalc.h" // 1. ����� �����ϰ�

// 2. DLL�� �ε��ؼ� ��ӵ� �Լ��� ȣ������ Proxy�� ���� ���
ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); // linux : dlopen()
												// windows : LoadLibrary()

	// DLL �ȿ��� ��ӵ� �Լ� ã��
	using FP = ICalc* (*)();
	
	FP f = (FP)ec_get_function_address(addr, "CreateProxy");
										// linux : dlsym()
									  // windows : GetProcAddress()

	ICalc* p = f(); // Proxy ��ü ����

	return p;
}

int main()
{
	ICalc* pCalc = ReloadProxy();

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}





