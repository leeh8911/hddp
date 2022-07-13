// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ����� ����� ����� �߰�
// ��� : ��ü�� ��� �߰��� �ƴ� Ŭ������ ��� �߰�
// ���� : Ŭ������ �ƴ� ��ü�� ����� �߰��ϴ� ��
class LeftMissile
{
	SpaceShip* ship; // "������" �Ǵ� "����" �� �ؾ� �մϴ�.
					 // ������ �����ϴ� ��ü�� "����ų��" �̶�� �ǹ�
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // ���� ��ü�� ����� ����ϰ�.
		std::cout << "Fire Left Missile" << std::endl; //���ο� ����߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss); // ss ��� ��ü�� ���ο� ����� �߰��ϰڴٴ� �ǹ�.
	lm.Fire();			 // ��ü�� "����߰� ��ü(������, Decorator)"�� ����	
				
				// lm�� ���ּ��� �ƴϰ�, ���ּ��� "���"�� �߰��ϴ� ��ü �Դϴ�.
}


