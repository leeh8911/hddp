#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

class RadioBox
{
	bool state;
public:
	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};
//------------------------------------------
// üũ �ڽ� 2���� �����ڽ� 2���� �ʿ��մϴ�
// ���� : �Ʒ� ó�� ����� 4���� ��ü�� ���θ� �˰� �־�� �մϴ�.
//        �ϳ��� ��ü�� ���� ��ȭ�� ������ ��ü�� ���¸� �����ϴ� �ڵ尡
//        4���� ��ü ��ο� �־�� �մϴ�.
//        ��ü�� ���谡 �ʹ� ������ ���ϴ�. - "�߰���(������)"�� ������
//											���մϴ�.
class MyCheck : public CheckBox
{
public:
	void ChangeState()
	{
		// üũ�ڽ� 2���� ��� üũ �ǰ� ����1�� üũ �Ǿ�߸� ��ư��
		// enable �ȴٰ� �����մϴ�.
		if ( GetCheck() == true  &&
			 check2.GetCheck() == true &&
			 radio1.GetCheck() == true &&
			 radio2.GetCheck() == false)
		{
			cout << "Button Enable" << endl;
		}
		else
		{
			cout << "Button Disable" << endl;
		}
	}
};
int main()
{
}











