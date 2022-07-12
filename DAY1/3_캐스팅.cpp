// 3_ĳ����.cpp
#include <iostream>
using namespace std;

// 1. C++�� ĳ������ ������ ���� �ٸ��� ����ؾ� �մϴ�.
//  1) static_cast
//    : �ٸ� Ÿ�� ���� ��ȯ�� ���˴ϴ�.
//      ������ �ִ� ��ȯ�� ���˴ϴ�.
//  2) reinterpret_cast
//    : �޸� ���ؼ� ����
//  3) const_cast
//    : ������� �����ϴ� �������� ����մϴ�.
//     - Ÿ���� ����ġ ������ �ذ��ϱ� ���� ����մϴ�.
//  4) dynamic_cast
//   : RTTI(Run Time Type Information)

void print(int* p)
{
	cout << *p << endl;
}

int main()
{
	// int* p = (int*)malloc(sizeof(int));
	int* p1 = static_cast<int*>(malloc(sizeof(int)));

	int n = 0x12345678;
	// char* p2 = static_cast<char*>(&n); // error!
	char* p2 = reinterpret_cast<char*>(&n);
	printf("%x %x %x %x\n", p2[0], p2[1], p2[2], p2[3]);

	const int c = 100;

	// int* p3 = static_cast<int*>(&c); // error!
	// int* p3 = reinterpret_cast<int*>(&c); // error!
	int* p3 = const_cast<int*>(&c);
	// *p3 = 200;
	print(p3);
}