#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T>
class slist_iterator {
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	// 인터페이스로 약속된 2개의 함수 이름 대신
	// 진짜 포인터와 같은 방법을 사용하기 위해
	// 연산자 재정의로..
	// 결국 개념은 동일한데, 일반 함수가 아닌 "연산자 재정의"

	inline T& operator*() { return current->data; }

	inline slist_iterator<T>& operator++() {
		current = current->next;
		return *this;
	}
};

template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	// 컨테이너 제작자는 자신의 반복자 이름을 약속된 형태로 외부에 알려야 함
	using iterator = slist_iterator<T>;

	// 포인터 반환이 아닌 값 반환
	iterator begin() { return iterator(head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	slist<int>::iterator p = s.begin();
	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;

}
// 위 코드가 "C#", "삼성 타이젠(C++)"이 사용하는 반복자
// java, python, swift 등 대부분도 함수 이름만 다를 뿐 구현은 유사
// 그런데.. 생각해 볼 만한 문제
// 1. moveNext() 등이 인터페이스로 약속되므로 가상함수
//	  이동시 오버헤드가 있음
// 2. s.getEnumerator() 가 반복자를 "new"로 만들고 있음
//    "delete"도 해야 하지 않을까?
// 3. 진짜 배열을 열거하는 방법과 다름
//		진짜 배열은 포인터를 사용하므로, ++로 이동