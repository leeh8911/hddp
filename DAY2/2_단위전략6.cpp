#include <iostream>

// STL �� ����
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;	// �޸� �Ҵ��. 
				// ������ ��� ��� �Լ� ������ �޸� �Ҵ�/������ �ʿ��ϸ�
				// �� ��ü�� �����ؾ� �մϴ�
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 

		T* temp = ax.allocate(n); // �Ҵ��� �ʿ� �Ҷ�
		//....
		ax.deallocate(temp, n); // ������ �Ҷ�

	}
};

