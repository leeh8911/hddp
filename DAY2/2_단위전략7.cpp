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
	// �� 2�� �Լ� ����, �Ʒ� 3���� ����� �� �ʿ� �մϴ�.
	// => ���������� �� ����ø� �˴ϴ�. ("���ø� �о�"�� �н��غ�����)
	using value_type = T;
	MyAlloc() {} // ����Ʈ ������
	template<typename U> MyAlloc(const MyAlloc<U>&) {} // ���ø� ������
};





int main()
{
	std::vector<int, MyAlloc<int> > v(5);

	std::cout << "------------";

	v.resize(10); 

	std::cout << "------------";
}