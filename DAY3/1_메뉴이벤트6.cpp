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

	f(10);		// f1(10),  f�� �ᱹ �Լ� �����Ϳ� ������ ���Դϴ�.

	// ������, function �� bind�� ����� ������ �ֽ��ϴ�.
//	f = &f2; // error...

	f = std::bind(&f2, 10, _1); // ���� �Լ��� ���� �Լ��� �����ؼ� 
								// f�� ���
	f(5); // f2(10, 5);


	// �Ʒ� �ڵ� �ϼ��� ������
	// 1. f3�� 3�� �̹Ƿ� �̾����� ���ڴ� 3���� �Ǿ�� �մϴ�.
	// 2. 3���� 1������ �����ؾ� �ϹǷ� "_1" ������ ���Ǿ�� �մϴ�
	f = std::bind(&f3, 2 , _1 , 2);

	f(5);  // f3(2, 5, 3);


	// ��� �Լ��� ��밡�� �մϴ�.
	// ��, �̶��� �Լ� ���ڻӾƴ϶� ��ü�� ���� �����Ǿ�� �մϴ�.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, 0, _1);

	f(5);	// dlg.close(0, 5);
			// (��ü������->*����Լ�)(0, 5);
}











// effective c++���� bind�� �ռ� �߷й����� ���� ������ �ִٰ� 
// ���� ����� �ߴ��� �������� ���� c++���� Ŀ���� �����ϱ� ���� ��� �ϳ���?
// => �������� ���ø��� ���� ǥ�������� �ַ� �����մϴ�.
// => bind ��� "����ǥ������ ����϶�" �� �Ǿ� �ִµ�..
//    ������ �̽��� �Ǵ� �κ��� �ƴϸ�(���� ���Ǵ� �ڵ�) ���� ���˴ϴ�.











