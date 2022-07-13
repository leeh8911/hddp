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
// ������� ������ Ŭ���� ����� : stack �� list �� ��� �����
//							�ܺο� �����ϰ� �ȴ�. 
//							���� �ڵ忡���� ���� �ʴ�.
/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()     { return std::list<T>::back(); }
};
*/
// ������ ����� ����� : stack ���忡���� list�� ����� �ܺο� �������� �ʴ´�.
template<typename T> class stack
{
//	std::list<T>* c; // �̷��� ������ �Ǵ� ���� ��� �ܺο� �ִ�
					 // list �� �����ϰ� �ǹǷ� ��ü�� ���� ����

	std::list<T> c;  // �̷��� ������ �Ǿ� ������ �ᱹ "Ŭ���� �����" �Դϴ�.
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
//	std::list<int> st = { 1,2,3 }; // �̹� �����ϴ� st ��ü��
									// ����ó�� ����Ҽ� �־��
									// ��ü ����� �Դϴ�.
	stack<int> s;
	s.push(10);

//	s.push_front(20); // ?? ����Ҽ� �ְ� �ؾ� �ұ�� ?
}





