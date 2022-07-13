// Decorator - 65 page
#include <iostream>

// Composite �� Decorator �� Ŭ���� ���̾�׷��� �����մϴ�.

// �ᱹ A�� B�� �ƴ϶� A�ڽŵ� ������ �ִ�
// ����� ���� ������ ���� �Դϴ�.
// => �̷��� �ϱ� ���� A, B�� ������ ��� Ŭ���� �ʿ�..

// �׷���.. "�� ����� ������ ���"�ϴ°�? ��� �ǵ��� �ٸ��ϴ�.

// Composite : ����� ������ ����ؼ� "���հ�ü" �� ����ڴٴ� �ǵ�
//             PopupMenu, Folder ��..

// Decorator : ��ü�� �������� ����� �߰��ϱ� ���� ���


// ��ü�� ��� �߰� ��ü�� ������ ��� Ŭ������ �ʿ� �ϴ�.

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

class LeftMissile : public Item
{
	Item* ship;					 
public:
	LeftMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); 
		std::cout << "Fire Left Missile" << std::endl; 
	}
};

class RightMissile : public Item
{
	Item* ship;
public:
	RightMissile(Item* s) : ship(s) {}

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

//	RightMissile rm(&ss); // �� �ڵ�� �翬�ϰ�
	RightMissile rm(&lm); // �� �ڵ尡 �Ǹ� ���� ������� ?
	rm.Fire();			  // ����� �߰��� ��ü�� �ٽ� ����߰�
}


