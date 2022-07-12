#include <iostream>

// STL �� ����
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;	
public:
	void resize(int n)
	{
		// C++ : ����ڰ� ������ Ŭ������ ��ӵ� �Լ��� ������ ���� �ƴ�
		// C#, java, swift : ����ڰ� Ŭ���� ���鶧 ������ ��Ű�ڴٰ� ǥ���ؾ� �Ѵ�.
		//					C#�� ��� �������̽� ����� �ʿ� �ϴ�.
		T* temp = ax.allocate(n); 
		//....
		ax.deallocate(temp, n); 

	}
};

template<typename T> struct MyAlloc //  where T  : IAllocator
{
	// allocate, deallocate
};

vector<int, MyAlloc<int>> v;
vector<int, int> v;
