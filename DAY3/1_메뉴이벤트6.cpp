#include <iostream>
#include <functional>
using namespace std::placeholders;


void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void close(int a, int b)
	{
		printf("Dialog close : %d, %d\n", a, b);
	}
};

int main()
{
	// �Լ� �����ʹ� "�������� ����" �ؼ� �����մϴ�.
//  void(*f)(int) = &f1; // ok

//	f = &f2; // error. f���� ���ڰ� �Ѱ��� �Լ��� �ּҸ� ������ �ִµ�
			//         f2�� ���ڴ� 2�� �Դϴ�.
				
	// C++11 ���� �Լ� �������� �Ϲ�ȭ ������ "std::function" �� �����˴ϴ�.

	// void(*)(int) : �Լ� ������ Ÿ��
	// void(int)    : �Լ� Ÿ��

	std::function<void(int)> f;

	f = &f1;	// ok
	f(10);		// f1(10)
}












