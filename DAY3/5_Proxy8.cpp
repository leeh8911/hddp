#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h" 
#include <memory>

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
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }

	~AutoPtr() { if (obj) obj->Release(); }

	// ����Ʈ �������� �ٽ� : -> �� * �����ڸ� �������ؼ� ��¥ ������ó�� ���̰��ϴ�.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	// C++ ǥ�ؿ� �̹� ����Ʈ �����Ͱ� �ֽ��ϴ�.
	// AutoPtr ������ ���� shared_ptr ����ϸ� �ȵǳ��� ?

	std::shared_ptr<ICalc> p1(ReloadProxy());
				// => �ڵ����� ����� ������!!
				// => �Ҹ��ڿ��� "delete" �մϴ�.
				// => ��, new �� DLL���� �ߴµ�..
				// => delete �� �������Ͽ��� �ϰ� �ִ� ���Դϴ�.

	AutoPtr<ICalc> p2(ReloadProxy());
				// => �� ����Ʈ �����ʹ� �Ҹ��ڿ��� "delete" �� �ƴ϶�
				// => Release() ȣ���Դϴ�.
				// => Release()�� DLL���� �Լ��̰�, ��������� 0�Ǹ� delete
				// => ��, delete�� DLL ���ο��� �մϴ�.

}






