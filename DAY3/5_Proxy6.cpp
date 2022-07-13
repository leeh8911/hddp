#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); 
	using FP = ICalc * (*)();

	FP f = (FP)ec_get_function_address(addr, "CreateProxy");

	ICalc* p = f(); // DLL ���ο��� new CalcProxy �ϹǷ�.. 
					// ����Ŀ��� delete �ؾ� ���� �������?

	return p;
}

int main()
{
	ICalc* pCalc = ReloadProxy(); // ó�����������͸� ������

	pCalc->AddRef();		// ���� ��� ����

	ICalc* pCalc2 = pCalc;	// �����͸� �����ص�

	pCalc2->AddRef();		// ������� ����


	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	// ����Ŀ��� delete �� �ƴ϶� ���� ��� ����
	pCalc->Release();  // ��������� 0�� �ƴ� 1�� ����

	std::cout << "------------" << std::endl;
	pCalc2->Release(); // �̶� �ı�..




//	delete pCalc; // ���� �ڵ��ϱ�� ?
				  // DLL ���ο��� new �� �����Ƿ� 
				  // delete �� DLL ���ο��� �ϴ� ���� �����ϴ�.
}





