// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// ������ ��ü(�౸���� ĳ����)�� ���鶧 ����ϴ� �� ������ �Լ���
// �������̽��� ����
struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes makeShoes() = 0;
	
	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		// �׷���, �� ������ ������� builder �� ���� �޶����ϴ�.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// ������ ĳ���͸� ���鶧 ����� �پ��� ������
class Korean : public IBuilder
{
public:
	Hat     makeHat() override     { return Hat("��"); }
	Uniform makeUniform() override { return Uniform("�Ѻ�"); }
	Shoes   makeShoes() override   { return Shoes("����"); }
};
class American : public IBuilder
{
public:
	Hat     makeHat() override { return Hat("�߱�����"); }
	Uniform makeUniform() override { return Uniform("�纹"); }
	Shoes   makeShoes() override { return Shoes("����"); }
};

int main()
{
	Korean k;
	American a;
	Director d;
	d.setBuilder(&k); // ���� ������ �����.. �� �Լ��� ������ü�� ����

	Character c = d.construct();
	std::cout << c << std::endl;

}