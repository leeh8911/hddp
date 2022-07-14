#include <iostream>

// 모든 컨테이너의 반복자 (열거자)가 지켜야 하는 인터페이스
template<typename T> 
struct IEnumerator {
	virtual T& getObject() = 0;
	virtual bool moveNext() = 0;

	virtual ~IEnumerator() {}
};

// 모든 컨테이너가 지켜야 하는 규칙
template<typename T>
struct IEnumerable { // 위 코드와 이름을 잘 구별!
	virtual ~IEnumerable() {}

	virtual IEnumerator<T>* getEnumerator() = 0;
};

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// slist의 반복자
// => 1번째 요소를 가리키다가, 주어진 규칙에 따라 이동할 수 있으면 됨
template<typename T>
class slist_enumerator : public IEnumerator<T> {
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr) : current(p) {}

	T& getObject() override{ return current->data; }
	bool moveNext() override {
		if (current->next == nullptr) {
			return false;
		} else {
			current = current->next;
			return true;
		}

	}
};

// 모든 컨테이너에서는 반복자를 꺼낼 수 있어야 함
template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	virtual IEnumerator<T>* getEnumerator() { return new slist_enumerator<T>(head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IEnumerator<int>* iter = s.getEnumerator();

	do {
		std::cout << iter->getObject() << std::endl;

	} while (iter->moveNext());

	delete iter; // 좋지 않음
					// 결국 스마트 포인터 사용해야 함
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