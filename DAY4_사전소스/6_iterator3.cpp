#include <iostream>

// ��� �����̳��� �ݺ��� (������)�� ���Ѿ� �ϴ� �������̽�
template<typename T> 
struct IEnumerator {
	virtual T& getObject() = 0;
	virtual bool moveNext() = 0;

	virtual ~IEnumerator() {}
};

// ��� �����̳ʰ� ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct IEnumerable { // �� �ڵ�� �̸��� �� ����!
	virtual ~IEnumerable() {}

	virtual IEnumerator<T>* getEnumerator() = 0;
};

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// slist�� �ݺ���
// => 1��° ��Ҹ� ����Ű�ٰ�, �־��� ��Ģ�� ���� �̵��� �� ������ ��
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

// ��� �����̳ʿ����� �ݺ��ڸ� ���� �� �־�� ��
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

	delete iter; // ���� ����
					// �ᱹ ����Ʈ ������ ����ؾ� ��
}
// �� �ڵ尡 "C#", "�Ｚ Ÿ����(C++)"�� ����ϴ� �ݺ���
// java, python, swift �� ��κе� �Լ� �̸��� �ٸ� �� ������ ����
// �׷���.. ������ �� ���� ����
// 1. moveNext() ���� �������̽��� ��ӵǹǷ� �����Լ�
//	  �̵��� ������尡 ����
// 2. s.getEnumerator() �� �ݺ��ڸ� "new"�� ����� ����
//    "delete"�� �ؾ� ���� ������?
// 3. ��¥ �迭�� �����ϴ� ����� �ٸ�
//		��¥ �迭�� �����͸� ����ϹǷ�, ++�� �̵�