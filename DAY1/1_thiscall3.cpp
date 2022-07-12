// 1_thiscall3.cpp
#include <iostream>
using namespace std;


class Dialog {
public:
	// void open(Dialog* this)
	void open() {
		cout << "Dialog open" << endl;
	}

	void close() {
		cout << "Dialog close" << endl;
	}

	// void()
	// : ���� ��� �Լ��� �Ϲ� �Լ��� �ñ״�ó�� �����մϴ�.
	//  - �Ϲ� �Լ� �����͸� ���� ���� ��� �Լ��� ȣ���� �� �ֽ��ϴ�.
	static void foo()
	{
		cout << "Dialog foo" << endl;
	}
};

int main()
{
	// void (*fp3)(Dialog*) = &Dialog::open;
	// : ����� �Ұ����մϴ�.

	void (*fp2)() = &Dialog::foo;
	fp2();


	// 1. ��� �Լ� ������ Ÿ���� ����� ���
	void (Dialog:: * fp)();

	// 2. ��� �Լ��� �ּҸ� ��� ���
	fp = &Dialog::open;

	// 3. ��� �Լ��� ȣ���ϱ� ���ؼ��� �ݵ�� ��ü�� �ʿ��մϴ�.
	//  => ��� �Լ� �����͸� ���� ��� �Լ��� ȣ���ϱ� ���ؼ��� �ݵ��
	//     ��ü�� �ʿ��մϴ�.
	Dialog dlg;
	(dlg.*fp)();  // .*
	
	
	Dialog* pDlg = &dlg;
	(pDlg->*fp)(); // ->*

}



#if 0
// ��� �Լ��� ��� �Լ� ������ �̾߱�
int add(int a, int b) { return a + b; }

// int n;
// : C++������ �̸��� ������ �������� Ÿ���Դϴ�.

// int x[3];
// : int[3]

// int add(int a, int b)
// : int(int a, int b)
int main()
{
	int(*fp)(int, int) = &add;
	int result = (*fp)(10, 20);
	
	int(*fp2)(int, int) = add;
	result = fp(10, 20);
	
	cout << result << endl;
}
#endif