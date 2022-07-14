// ��� ���� ��, static ������ �Լ��� �� ��� ���� Ŭ������ ������ ���ӵǳ���?


// ��ü�� 5���� ����� �ϰ� ����
class LimitCount{
	static int cnt;
public:
	LimitCount() { if (++cnt > 5) throw 1; }
	~LimitCount() { --cnt; }
};

int LimitCount::cnt = 0;

// Mouse�� Keyboard�� 5���� ����� �ϰ� �ʹ�..
class Mouse : public LimitCount {

};

class Keyboard : public LimitCount {

};


int main() {
	LimitCount c1[2];
	Mouse c2[2];
	Keyboard c3[2];
}