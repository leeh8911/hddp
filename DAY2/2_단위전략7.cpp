#include <iostream>
#include <vector>

// ����� ���� allocator �� ���鶧�� �̸� ��ӵ� ��Ģ(�Լ��̸�)�� 
// ���Ѿ� �մϴ�.
// cppreference.com ���� "1��° ȭ�� �����ʿ��� named requirement"
template<typename T>
class MyAlloc
{
public:

};



int main()
{
	std::vector<int, MyAlloc<int> > v(5);

	std::cout << "------------";

	v.resize(10); 

	std::cout << "------------";
}