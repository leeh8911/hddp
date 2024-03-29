// QA1.cpp - Adapter3 복사해오세요


#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;


// private 상속 : 기반 클래스의 모든 멤버를 물려 받을때 private영역에 놓겠다는것
//				내부적으로만 사용하고, 외부 노출 하지 않겠다.

// 그런데, stack 의 경우는 "포함"이 좋습니다.
// 단, private 상속은 "list 가 가진 가상함수가 있다면 override" 할수 있는
// 기회를 가지게 됩니다.

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

	s1.push_front(10); // error. private 상속을 받았으므로 private 멤버
	s2.push_front(10); // error. stack2에 push_front 함수는 없다.
}





