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
template<typename T> class TWiceVisitor : public IVisitor<T>
{
public:
	void visit(T& v) override {}
};




int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.Accept(&tv);

	ShowVisitor<int> sv; 
	s.Accept(&sv);

}





