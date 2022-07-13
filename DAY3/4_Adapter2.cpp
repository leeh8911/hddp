#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 75 page.. 
// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.

// TextView : ���ڿ��� �����ߴٰ� ȭ�鿡 �̻ڰ� ����� �ִ� Ŭ����
class TextView
{
	// ��Ʈ����, ũ��, ����, ��Ÿ��
	string data;
public:
	TextView(string s) : data(s) {}

	void Show() { cout << data << endl; }
};

// TextView tv("hello");
// tv.Show(); 





class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { cout << "Draw Rect" << endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { cout << "Draw Circle" << endl; }
};

// ����� ������ ����
// Ŭ���� ����� : 
// ��ü   ����� : 
// �Ʒ� �ڵ尡 "Ŭ���� �����" �Դϴ�.
class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void Draw() override { TextView::Show(); };
};

// �Ʒ� �ڵ尡 "��ü �����" �Դϴ�.

class ShapeAdapter : public Shape
{
	TextView* txtView; // �ٽ�(������, �Ǵ� ����)
public:
	ShapeAdapter(TextView* v) : txtView(v) {}

	void Draw() { txtView->Show(); }
};

int main()
{
	vector<Shape*> v;

	TextView tv("hello");	// TextView : Ŭ����
							// tv       : ��ü

	// �̹� �����ϴ� tv�� ���������⿡ ������ ������� ?
//	v.push_back(&tv); // error. tv �� TextView Ÿ���ε�..
						//		Shape�� ���� ��ӹ��� �ʾҴ�.
 
	v.push_back( new ShapeAdapter(&tv) ); // �̹� �����ϴ� ��ü��
										// ����ͷ� ������ ����
										// "����(������)" ��Ȱ


}







