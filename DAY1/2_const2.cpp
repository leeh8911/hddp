// 2_const2.cpp

#include <iostream>
using namespace std;

// ���
// 1. ������ Ÿ�� ��� - constexpr
// 2. ��Ÿ�� ���

int main()
{
	int n2 = 100; // ����
	cin >> n2;


	// constexpr int n = 42;
	const int n = n2;
	
	int* p = const_cast<int*>(&n); // const int* -> int*

	*p = 100; // !!
		
	cout << n << endl;  // 42
	cout << *p << endl; // 100
}