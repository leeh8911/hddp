#include <iostream>
#include <vector>
#include <allocators> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// ��� 1. new / delete �� ���� ���
	int* p1 = new int[10];
	delete[] p1;



	// ��� 2. allocator ���
	std::allocator<int> ax;    // C++ǥ�� �޸� �Ҵ��
								// (���������δ� new/delete ���)

	int* p2 = ax.allocate(10); // int 10�� �Ҵ��� �޶�
								// �ᱹ "new int[10]"

	ax.deallocate(p2, 10); // "delete[] p2"

}