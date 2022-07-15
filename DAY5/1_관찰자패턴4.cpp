#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void Update(int n) = 0;
	virtual ~IGraph() {}

	Subject* subject;

	// MFC/QT �� GetDocument() ��� �Լ��� �ֽ��ϴ�.
	virtual Subject* getSubject() { return subject; }
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
	// �����Լ� �����ǽ� ��ȯ Ÿ���� �����Ҽ� �ִ�.. ��� ������ �ֽ��ϴ�.
	Table* getSubject() override 
	{
		return static_cast<Table*>(subject); 
	}

	void Update(int n) override
	{
		Table* table = getSubject(); // �ڽŰ� �����
									// Subject(Table)�� ������ ���

		int data = table->getData();


		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};



int main()
{
	Table t;

	BarGraph bg; t.attach(&bg);

	t.edit(); 
}



