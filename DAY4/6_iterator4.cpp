#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr): current(p)
	{
	}

	// �������̽��� ��ӵ� 2���� �Լ� �̸� ���
	// ��¥ �����Ϳ� ���� ����� ����ϱ� ����
	// ������ �����Ƿ�..
	// �ᱹ ������ �����ѵ�. �Ϲ� �Լ��� �ƴ� "������ ������"

	inline T& operator*()  { return current->data; }

	inline slist_iterator<T>& operator++()
	{
		current = current->next;
	
		return *this; // ++ �����ڴ� �ڽ��� ������ ��ȯ�ϴ� ��Ģ�� �ֽ��ϴ�.
	}
};

// ��� �����̳ʿ����� �ݺ��ڸ� ������ �־�� �Ѵ�.
template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	// �����̳� �����ڴ� �ڽ��� �ݺ��� �̸��� ��ӵ� ���·� �ܺο� �˷��� �մϴ�.

	using iterator = slist_iterator<T>;

	// ������ ��ȯ�� �ƴ� �� ��ȯ
//	slist_iterator<T> begin() 
	iterator begin()
	{
		return iterator(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

//	slist_iterator<int> p = s.begin();
	
//	slist<int>::iterator p = s.begin();

	auto p = s.begin();



	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;



}

// �� �ڵ尡 "C#", "�Ｚ Ÿ����(C++)" �� ����ϴ� �ݺ��� �Դϴ�.
// java, python, swift �� ��κ� �� �Լ� �̸��� �ٸ��� ������ ���� �մϴ�.
// 
// �׷���.. ������ �� ����
// 1. moveNext()���� �������̽��� ��ӵǹǷ� �����Լ� �Դϴ�.
//    �̵��� ������� �ֽ��ϴ�.

// 2. s.getEnumerator() �� �ݺ��ڸ� "new"�� ����� �ֽ��ϴ�.
//    delete �ؾ� ���� �������?

// 3. ��¥ �迭�� �����ϴ� ����� �ٸ��ϴ�.
//    ��¥ �迭�� �����͸� ����ϹǷ� ++ �� �̵�