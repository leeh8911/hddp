// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.

	// 1. �Լ����ڷ� ��������.
	g.DrawLine(0, 0, 100, 100, red, 10);  // ����, �β� ����
	g.DrawLine(0, 0, 200, 200, blue, 20); // ����, �β� ����

	// 2. Graphics ��ü�� �Ӽ������� ��������.
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
}









