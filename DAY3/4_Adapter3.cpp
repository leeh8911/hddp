#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// STL �� Adapter

// STL �� list �� �ִµ�, ����ڰ� stack �� �䱸�մϴ�.
// 1. stack �� ������
// 2. list �� �Լ� �̸��� �����ؼ� stack ó�� ���̰� ����.

// list �� �Լ� �̸� "push_back" �� "push" �� �����ؼ�
// ����ó�� ���̰� ����.
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()     { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
}





