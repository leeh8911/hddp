// QA1.cpp - Adapter3 �����ؿ�����


#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;


// private ��� : ��� Ŭ������ ��� ����� ���� ������ private������ ���ڴٴ°�
//				���������θ� ����ϰ�, �ܺ� ���� ���� �ʰڴ�.

// �׷���, stack �� ���� "����"�� �����ϴ�.
// ��, private ����� "list �� ���� �����Լ��� �ִٸ� override" �Ҽ� �ִ�
// ��ȸ�� ������ �˴ϴ�.

template<typename T> class stack1 : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()     { return std::list<T>::back(); }
};

template<typename T> class stack2
{
	std::list<T> c; 
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack1<int> s1;
	stack2<int> s2;

	s1.push_front(10); // error. private ����� �޾����Ƿ� private ���
	s2.push_front(10); // error. stack2�� push_front �Լ��� ����.
}




