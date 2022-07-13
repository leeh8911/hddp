#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	using FP = ICalc * (*)();
	FP f = (FP)ec_get_function_address(addr, "CreateProxy");
	ICalc* p = f(); 
	return p;
}

// ��������� �ڵ����� �����ϴ� ����Ʈ�����͸� �����մϴ�.
// ����Ʈ ������ : ������ ��Ȱ�� ��ü, ����/����/����/�Ҹ��� �������� �߰� ��ɼ���
template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)       : obj(p) {}
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) {}

	~AutoPtr() {}
};

int main()
{
	AutoPtr<ICalc> p1 = ReloadProxy();
	AutoPtr<ICalc> p2 = p1;
}



/*
int main()
{
	ICalc* pCalc = ReloadProxy(); 

	pCalc->AddRef();		// ���� ��� ����

	ICalc* pCalc2 = pCalc;	// �����͸� �����ص�

	pCalc2->AddRef();		// ������� ����

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

	pCalc->Release(); 

	std::cout << "------------" << std::endl;
	pCalc2->Release(); 

}


*/


