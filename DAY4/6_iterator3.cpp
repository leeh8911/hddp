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

// slist �� �ݺ���
// => 1��° ��Ҹ� ����Ű�ٰ�, �־��� ��Ģ�� ���� �̵��Ҽ� ������ �˴ϴ�.
template<typename T> 
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr)
		: current(p)
	{
	}
	// �������̽��� ��ӵ� 2���� �Լ� ����
	T& getObject() override { return current->data; }

	bool moveNext() override
	{
		// �츮�� slist �̹Ƿ� �Ʒ� ó���̵�
		// vector ��, �ٸ� ������� �ش��ϴ� ������ �°� �̵�
		current = current->next;
		return current != nullptr; // ���� ���޿���
	}
};
//slist_enumerator<int> p(300����);
//p.moveNext();
//int n = p.getObject();

// ��� �����̳ʿ����� �ݺ��ڸ� ������ �־�� �Ѵ�.
template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IEnumerator<T>* getEnumerator()
	{
		// 1��° ��Ҹ� ����Ű�� �ݺ��� ��ü ��ȯ
		return new slist_enumerator<T>(head);
	}
};
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IEnumerator<int>* p = s.getEnumerator();

	std::cout << p->getObject() << std::endl; // 40
	p->moveNext();
	std::cout << p->getObject() << std::endl; // 30

	delete p; // ���� �ʽ��ϴ�.
			  // �ᱹ ����Ʈ ������ ����ؾ� �մϴ�.
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