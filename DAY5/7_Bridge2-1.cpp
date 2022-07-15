// ���� ������ ���� Ŭ���� 
// Point�� ��� ����� ���⼭ ����
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 



// �Ʒ� Ŭ������ ����ڰ� ����ϰ� �Ǵ� ������(�߻���, Bridge)�Դϴ�.
// Point.h
//#include "PointImpl.h" // �̷��� ���� �ʰ�
class PointImpl; // �̷��Ը� �ص� ������ ������ ��밡��

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h" 

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }




// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

// ���� ���� "Point" �������� �����
// 1. ������ �ӵ��� �������ϴ� 
//  => PointImpl.h �� ����Ǿ  CLient �ڵ�� �� �������� �ʿ� ����.

// 2. �Ϻ��� ���������� �����ϴ�.

// �� �����

// "PIMPL" �̶�� �θ��ϴ�.

// Point to IMPLementation
// 
// "�����Ϸ� ��ȭ��" �̶�� �մϴ�.


// ��ü���� �������� �ٽ� 3. "�������� ����� ��"
// ��?? � ������ �������� ����µ�.. ����(�ǵ�)�� ����..
// 
// 
// �����	 ===> stack ======>	list			// �Լ��̸��� �����ؼ� �ٸ���ó��
//											// ���̰� . "Adapter ����"
// 
// �����	 ===> TCPServer ==>	Socket, IPAddress... // ����ϰ� ����..
//												// �Ѱ��� ������ �������̽�
//												// facade
// 
// �����	 ===> CalcProxy ==>	CalcServer	// �پ��� �뵵�� "�������� ������"
//										// Proxy
// 
// �����	 ===> MP3 ========>	IMP3	// update �� ���ϰ� �ϱ� ���ؼ�
									// ������ �߻��� ��ȣ ������ update
									// bridge




