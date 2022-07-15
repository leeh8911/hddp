// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};

struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------

// WinDialog �� OSXDialog �� ������ �ڵ尡 �����ϴ�.
// ������ �ڵ�� "��� Ŭ����"�� �����ϸ� ���մϴ�.
class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit  = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// ��ü�� ����� ���� �������̽��� ���� �ϰ� ���������
	// � ��ü�� �������� �Ļ�Ŭ������ ����.
	// "Factory Method" ����
	// "Template Method" �� ����������, �˰����� ������ �ƴ� "������ ��ü�� Ÿ��"�� ����
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit()   = 0;
};

class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit()     override { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	// IButton* ��� OSXButton* ���� �������ص� �˴ϴ�. => �����ϴ�.
	// �̷� ����� "���� ��ȯ" �� ��Ģ �̶�� �մϴ�.
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit()     override { return new OSXEdit; }
};


int main(int argc, char** argv)
{

}








