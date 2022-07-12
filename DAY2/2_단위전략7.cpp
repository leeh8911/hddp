#include <iostream>
#include <vector>

// ����� ���� allocator �� ���鶧�� �̸� ��ӵ� ��Ģ(�Լ��̸�)�� 
// ���Ѿ� �մϴ�.
// cppreference.com ���� "1��° ȭ�� �����ʿ��� named requirement"
template<typename T>
class MyAlloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("allocate %d ��, %p\n", sz, p);

		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate %d ��, %p\n", sz, p);
		free(p);
	}
};





int main()
{
	std::vector<int, MyAlloc<int> > v(5);

	std::cout << "------------";

	v.resize(10); 

	std::cout << "------------";
}