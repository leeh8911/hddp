#include <iostream>

// ��� 3. ���ϴ� ���� �ٸ� Ŭ������!

// ĳ���ʹ� ������ ȹ�濩�ο� ���� ������ ����ȴ�.
// ����Ǿ�� �ϴ� ����(�Լ�)���� �������̽��� ����
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// jump(), slide()  �� ���ؾ� �ϴ� ��� ����Լ��� ���⿡ �߰�
};

class Charater
{
	int gold;
	int item;
	IState* state;
public:
	void setState(IState* p) { state = p; }

	// ĳ������ ��� ������ "���� ��ü"�� �����մϴ�.
	void run() { state->run(); }
	void attack() { state->attack(); }
};
// �����ۿ� ���� ������ ������ ������ ���� ��ü�� ����� �˴ϴ�.
class NoItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class RedItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};
class BlueItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
class StarItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
int main()
{
	NoItem ni;
	RedItem ri;
	BlueItem bi;
	StarItem si;

	Charater* p = new Charater;
	p->setState(&ni);
	p->run();
	p->attack();

	// ���� ������ ȹ�� ���ο� ���� ������ �����մϴ�.
	p->setState(&bi);
	p->run();
	p->attack();

	p->setState(&si);
	p->run();
	p->attack();

	p->setState(&ni);
	p->run();
	p->attack();

	// �� �ڵ��� �ǹ�
	// ��ü�� 
	// 1. "����(�������Ÿ)�� ������� �ʴµ�"
	// 2. "����(����Լ�)" �� ����˴ϴ�.
	//    ������ �ٸ� Ŭ������ ����ϴ� �� ó�� ���̰� �˴ϴ�.
}



