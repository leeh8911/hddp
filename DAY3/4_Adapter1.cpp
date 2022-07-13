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

// ���������� �ý��ۿ�, �簢��, �� �� �ƴ϶� "Text" �� �����ϴ� ��ɵ� �ʿ��ϴ�.
// ���� ������ : ȭ�� ��½� "Draw()" ���
// TextView  : ȭ�� ��½� "Show()" ���
// ��, �������̽�(�Լ��̸�)�� �ٸ���.

// �����(Adapter) ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ� 
//					    �ý����� �䱸�ϴ� �������� �����Ѵ�.

// ����� ������ ����
// Ŭ���� ����� : 
// ��ü   ����� : 

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	// �Ʒ� �ڵ尡 "Show" ��� �Լ� �̸��� "Draw" �̸����� �����Ѱ�
	void Draw() override { TextView::Show(); };
};

int main()
{
	vector<Shape*> v;
	v.push_back(new Text("hello"));

	v[0]->Draw();
}







