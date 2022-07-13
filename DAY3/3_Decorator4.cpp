#include <iostream>


class Item
{
public:
	virtual void Fire() = 0;
	virtual ~Item() {}
};


class SpaceShip : public Item
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ��� �߰� ��ü���� ������ Ư¡�� ���� ������ �ֽ��ϴ�.
// �� ���, "������ Ư¡�� ���� ��� Ŭ������ �����ϸ� �����ϴ�."

class IDecorator : public Item
{
	Item* ship;
public:
	IDecorator(Item* s) : ship(s) {}
};

class LeftMissile : public IDecorator
{
public:
	LeftMissile(Item* s) : IDecorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public IDecorator
{
public:
	RightMissile(Item* s) : IDecorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};


int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);
	lm.Fire();

	RightMissile rm(&lm);
	rm.Fire();			 
}


