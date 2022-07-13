// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// ����� ����� ����� �߰�
// ��� : ��ü�� ��� �߰��� �ƴ� Ŭ������ ��� �߰�
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // ���� ����� �����ϰ�..
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ��ɼ���
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm; // ss��� ��ü�� ����� �߰��Ȱ��� �ƴ϶�
	lm.Fire();		// ����� �߰��� ���ο� ��ü�� ���� �Ȱ�
}