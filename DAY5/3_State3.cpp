#include <iostream>

// ��� 2. ���ϴ� ���� �����Լ���!!

class Charater
{
	int gold;
	int item;
public:
	void run() { doRun(); }
	void attack() { doAttack(); }

	virtual void doRrun() { std::cout << "run" << std::endl; }
	virtual void doAttack() { std::cout << "attack" << std::endl; }
};



int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



