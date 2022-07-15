// 8_�޸��� - 178
#include <iostream>
#include <vector>


class Graphics
{
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::vector<Memento*> v; // �Ǵ� map, unordered_map��

	int penWidth = 1;
	int penColor = 0;
	int temporary_data;
public:
	int Save()
	{
		Memento* p = new Memento;
		p->penColor = penColor;
		p->penWidth = penWidth;
		v.push_back(p);

		return v.size(); //���° �����ߴ°��� token����
						 // ���ڵ� ���ٴ� map<key, Memento*> �� �����մϴ�.
	}
	void Restore(int token)
	{
		penColor = v[token - 1]->penColor;
		penWidth = v[token - 1]->penWidth;
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // ��ü�� ���¸� �����ߴٰ� ���� �Ҽ� �ְ� �Ѵ�.
						  // "memento" ����
						  // ĸ��ȭ�� ���� ���� �ʰ�
							// (��,��ü�� ���������� ������ �����Ѵٴ� �ǹ�)
	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// ó���� �׷ȴ� ���� �����ϰ� �׸��� �ʹ�.
	g.Restore(token);
}









