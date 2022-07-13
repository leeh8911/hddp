#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const char* buff) 
	{
		printf("%s ����\n", buff);
	}
};

int main()
{
	// C++�� �Ҹ��ڸ� Ȱ���ϸ� �ڵ����� �ڿ� ������ �Ҽ� �ֽ��ϴ�.
	FileStream fs("a.txt");


	// C ���� ����ڰ� ���� �ڿ��� �����ؾ� �մϴ�
//	FILE* f = fopen("a.txt", "wt");
//	fclose(f);
}