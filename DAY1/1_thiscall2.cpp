// 1_thiscall2.cpp
#include <iostream>
using namespace std;

class Sample {
	int data;
public:
	// void f1(Sample* this) {}
	void f1() { cout << "f1" << endl; }

	int f2() { cout << "f2" << endl; return 0; }

	// 1. Microsoft MFC
	// 2. AOSP
	// : C++ ǥ�ؿ����� �� ��ü�� ���� �Լ� ȣ���� ������ �����Դϴ�.
	//   - MSVC
	//   - GCC
	//   - LLVM
	static int safe_f3_2(Sample* self) 
	{
		if (self)
			return self->f3();
		return 0;
	}

	int safe_f3()
	{
		if (this)
			return f3();

		return 0;
	}

private:
	int f3() { cout << "f3" << endl; return data; }
	//                                   this->data;
};

int main()
{
	Sample* p = nullptr; // �� ��ü �Դϴ�.

	p->f1(); // Sample::f1(p) / Sample::f1(nullptr)
	p->f2();

	// p->f3();
	// p->safe_f3();

	Sample::safe_f3_2(p);
}