// CRTP.cpp
// ��� ���� ��, static ������ �Լ��� 
// �� ��� ���� Ŭ������ ������ ���� �Ǵ°ǰ���?

// ��ü�� 5���� ����� �ϰ� �ʹ�.
class LimitCount
{
	static int cnt;
public:
	LimitCount() { if (++cnt > 5) throw 1; }
	~LimitCount() { --cnt; }
};
int LimitCount::cnt = 0;

// Mouse �� Keyboard �� 5���� ����� �ϰ� �ʹ�.
class Mouse : public LimitCount
{
};
class Keyboard : public LimitCount
{
};
int main()
{
	Mouse m[3];
	Keyboard k[3];
}