#include <iostream>

int main()
{
	slist<int> s = { 1,2,3,4,5 }; // ��� ��Ұ� ������ �޸�

	vector<int> v = { 1,2,3,4,5 }; // ��� ��Ұ� ���ӵ� �޸�

	// ���ӵ� �޸𸮸� ����ϴ� �����̳ʿ� 
	// ���ӵ��� ���� �޸𸮸� ����ϴ� �����̳ʴ�
	// ����� ��ȸ ����� �ٸ��ϴ�.
	
	// iterator ����
	// => �����̳��� ���α����� ������� ������ ������� 
	//    ��Ҹ� �����ϰ� ����.

	// �ٽ� 1. ��� �����̳ʴ� �ݺ��ڶ�� ��ü�� ������ �־�� �Ѵ�.
	list�ݺ���   p1 = s.getEnumerator();
	vector�ݺ��� p2 = v.getEnumerator();


	// ��� �ݺ��ڴ� ������ ���ƾ� �մϴ�.
	// => ��� �ݺ����� �Լ� �̸��� ����ϱ� ����
	//    �������̽��� �־�� �Ѵٴ� �ǹ�. 
	int n1 = p1.getObject();
	int n2 = p2.getObject();

	p1.moveNext();
	p2.moveNext();

}




