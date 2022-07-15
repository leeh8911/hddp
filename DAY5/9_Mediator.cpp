// 6_Mediator - ������ ���� 
#include <iostream>

// Mediator(������ ����)
// => ��ü���� ��ȣ ���谡 �����ϸ� �����ڸ� ������.
// => M:N�� ���踦 1:N�� ����� ����(1:������)
// 
// => M:N => ��ü���� ���� ��θ� �˾ƾ� �Ѵ�.
//    1:N => �����ڸ� ��ü���� �˸� �ȴ�.

// => ��� ��Ģ�� �����ڸ� �˸� �ȴ�.

// Observer : 1�� ��ȭ�� ��ο��� �˸�
// Mediator : �����ڵ��� ��ȭ�� �ٸ� �����ڿ��� �˸��ų�
//            �����ڵ��� ��ȭ�� ������ �Ǵ��� ����









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

int main()
{
}



