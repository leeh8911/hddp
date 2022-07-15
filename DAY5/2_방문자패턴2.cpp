#include <iostream>
#include <list>
#include <vector>

// �湮��(Visitor)�� �������̽�
template<typename T> struct IVisitor
{
	virtual void visit(T& v) = 0;

	virtual ~IVisitor() {}
};


// ���� �پ��� �湮�ڸ� ���� �մϴ�.
// �湮�ڴ� "��� �Ѱ��� ���� ����" �� ���� �ϸ� �˴ϴ�.
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& v) override { v *= 2; }
};
//=====================================
// ���հ�ü�� �湮�ڸ� �޾� �鿩�� �մϴ�.
template<typename T> struct IAccept
{
	virtual void Accept(IVisitor<T>* visitor) = 0;
	virtual ~IAccept() {}
};

// STL�� �湮�� ������ ������� �ʰ� �ֽ��ϴ�.
// list �� Ȯ���ؼ� �湮�� ������ ��� �߰�
template<typename T> 
class MyList : public std::list<T>, public IAccept<T>
{
public:
	// std::list �� ��� �����ڸ� �״�� ����Ҽ� �ְ� �ش޶�!!
	// => C++11 ���� �߰��� ������ ���
	
	using std::list<T>::list;


	void Accept(IVisitor<T>* visitor) override
	{
		// �湮�� : �Ѱ��� ��ҿ� ���� ���� ����
		// ����, �ڽ��� ��� ��Ҹ� �湮�ڿ� �����մϴ�.

		for (auto& e : *this)   // "*this" : �ᱹ std::list �Դϴ�.
			visitor->visit(e);

	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.Accept(&tv);

//	ShowVisitor<int> sv; 
//	s.Accept(&sv);

}





