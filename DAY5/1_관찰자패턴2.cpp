//1_����������1 - 94 page
#include <iostream>
#include <vector>


// ��� Graph �� ������ �������̽�
struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}
};

// Table �� �ٷ�� ����Ÿ�� ���°� ����Ǿ
// ������ ������ �⺻ ������ �����ϴ�
// ������ ������ �⺻ ������ �����ϴ� ��� Ŭ������ �����Ѵ�.

// ������ ����� "Subject" ��� �մϴ�.
class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	virtual ~Subject() {}
};

// ���� ������ ������ ����Ϸ��� "Subject" �� ���� �Ļ��Ǹ� �˴ϴ�.
class Table : public Subject
{
	int value; // table �� data ��
public:
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value; 
			notify(value);		
		}
	}
};



//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

class LineGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Line Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "-";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;

	// �׷��� ��ü�� ����� Table�� ����
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	LineGraph lg; t.attach(&lg);

	t.edit(); // Table ���� ���� .. 
}



