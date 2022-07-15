#include <iostream>

// ��� 2. ���ϴ� ���� �����Լ���!!

class Charater
{
	int gold;
	int item;
public:
	void run() { doRun(); }
	void attack() { doAttack(); }

	virtual void doRun()   { std::cout << "run" << std::endl; }
	virtual void doAttack() { std::cout << "attack" << std::endl; }
};
// ���� �� ������ ���� ������ �����ؾ� �ϹǷ� �Ļ� Ŭ�������� �����Լ� ������
class RedItemCharacter : public Charater
{
public:
	void doRun() override { std::cout << "fast run" << std::endl; }
	void doAttack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedItemCharacter; // ���� ĳ���Ͱ� ������ ȹ��ƴ϶�..!!
							// ���ο� ĳ���͸� ���� ��
							// �츮���� �ʿ��� ����
							// ���´� ����(���� ��ü ���) �ϴµ�
							// ����(��� �Լ�)�� ��ü�ϰ� ������
	p->run();
	p->attack(); 
}



