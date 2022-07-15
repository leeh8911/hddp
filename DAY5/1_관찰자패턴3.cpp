#include <iostream>
#include <vector>

// Table �� ����� �׷����� �ٽ� �׸����� Graph ���� Table�� ����Ÿ�� �˾ƾ� �մϴ�
// Table �� Graph �� ���� �ϴ� ���          : Push ���
// Graph �� Table �� ���� �ؼ� ���� ���� ��� : Pull ���

class Subject; // Ŭ���� ���� ����

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}

	// �׷����� �ڽ��� ����� Table(Subject)�� �˾ƾ� �����Ҽ� �ִ�.
	Subject* subject; 
};

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p);
		p->subject = this;
	}
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
	virtual ~Subject() {}
};


class Table : public Subject
{

	int value; // table �� data ��
public:

	// Table�� ���� �پ��� ����Ÿ�� ������ �ִ� �Լ� ����
	int getData() const { return value; }   


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
	// Table ����� �Ʒ� �Լ��� ȣ��˴ϴ�. �̶�
	// 1. Table �� � ����Ÿ�� ����Ǿ����� �Լ� ���ڷε� �뺸 ������ �ְ�
	// 2. �� �Լ� �ȿ��� Table�� ��� �Լ��� ȣ���ؼ� �� �˴ϴ�.

	void Update(int n) override
	{
	//	int data = subject->getData();  // error
		// subject �� Table�� ����Ű���� Ÿ����
		// Subject* �Դϴ�. 
		// �׷���, Table ������ ����� ������ �ȵ˴ϴ�.

		// �׷��� �׻� �� �����ο����� ĳ������ �����ϰ� �˴ϴ�.
		Table* table = static_cast<Table*>(subject);

		int data = table->getData();

		// MFC�� "Doc/View" ����, QT "Model/View"
		// java, C# �� MVC ���� ��� �� �����ε�..
		// �׻� ĳ������ �����ϴ� �˴ϴ�.



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



