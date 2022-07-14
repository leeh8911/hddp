#include <iostream>


// ��� �����̳��� �ݺ���(������)�� ���Ѿ� �ϴ� �������̽�
template<typename T> struct IEnumerator
{
	virtual T& getObject() = 0;
	virtual bool moveNext() = 0;

	virtual ~IEnumerator() {}
};

// ��� �����̳ʰ� ���Ѿ� �ϴ� ��Ģ
template<typename T> struct IEnumerable   // ���ڵ�� �̸� �� �����ϼ���
{
	virtual IEnumerator<T>* getEnumerator() = 0;
	virtual ~IEnumerable() {}
};








template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
}