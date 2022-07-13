#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;


/*
template<typename T, typename C = std::deque<T> >
class stack
{
	C c;    // STL �� ��� ���� �����̳ʴ� ������ �����ϴ�.!!
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top()   { return c.back(); }
};
*/
#include <stack> // C++ ǥ���� "stack" �� �� ó�� ������� �ֽ��ϴ�.
				// ����, "stack adapter" ��� �θ��ϴ�.
				// ���������̳ʸ� ���� ó�� ����ϵ��� "�������̽�(�Լ��̸�)"��
				// ������ �ִ� �����Դϴ�.

int main()
{
	std::stack<int> s; // std::deque  �� ����ó�� ����Ҽ� �ְ� �ش޶�� ��
	s.push(10);

	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
}





