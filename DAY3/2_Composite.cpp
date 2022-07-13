#include <iostream>
#include <vector>
#include <string>

// ���� ��ü(Folder)�� ���� ��ü(File)�� ����������
// ���� ��ü �ڽŵ� �����Ҽ� �ֽ��ϴ�.
// => ���հ�ü�� ������ü�� ������ ��� Ŭ������ �ʿ��մϴ�.

class Item
{
	std::string name;
public:
	Item(const std::string& n) : name(n) {}

	// ������ �ڽŸ��� ũ�Ⱑ �ְ�
	// ������ �ڽŸ��� ũ��� ������, ũ�⸦ ���Ҽ��� �ֽ��ϴ�.
	virtual int get_size() const = 0;
};
// �ᱹ �� �ڵ�� "BaseMenu" �� �ڵ� ���¿� ���� ������ ����Դϴ�.

class File : public Item
{
	int size;
public:
	File(const std::string& name, int sz) : Item(name), size(sz) {}

	int get_size() const override { return size; }
};

class Folder : public Item
{
	std::vector<Item*> v; // Composite ������ �ٽ�.. "Item*" ����
public:
	Folder(const std::string& name) : Item(name) {}

	void add_item(Item* p) { v.push_back(p); }

	int get_size() const override
	{
		// ������ ������ - �ٽ�!!
	}
};

// �Ʒ� �Լ� �̸� �����ؼ� ������ ������(getSize => get_size, 
//								   addItem => add_item)
// Item �� ����Ҹ��� �߰��� �ּ��� "virtual ~Item(){}"

int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	cout << f2->getSize() << endl; // 20
	cout << fo1->getSize() << endl; // 10
	cout << root->getSize() << endl; // 30
}

