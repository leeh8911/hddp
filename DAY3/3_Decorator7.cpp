#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Stream
{
public:
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}

};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

	// ���Ͽ� ���� �����ؼ� ���� ����� �ʿ� �մϴ�. 
	// ��� �ϴ� ���� �ּ� �ϱ�� ?
	// 1. ����Ÿ�� ���� �����ϰ� ����
	// => �̷����� ���� �Ѵٸ� �Ź� �ؾ� �ϴϱ� ���� �մϴ�.

	// 2. FileStream �ȿ� "zippedWrite" �� ������.
	// => NetworkStream, PipeStream ���� ������ �Ѵ�.
	// => �䱸������ ���涧 ���� "���� Ŭ������ ����"�ϴ� ���� ���� �ʴ�. OCP����

	// 3. ��� ��Ʈ���� ��� Ŭ������ "Stream" �� ��������.
	// => �䱸������ ���涧 ���� "���� Ŭ������ ����"�ϴ� ���� ���� �ʴ�. OCP����

	// 4. ���� Ŭ������ �������, ����� �߰��ϴ� ��ü�� ����� ���!!
	// => Decorator

	fs.Write("Hello"); // ���Ͽ� �׳ɾ��� 
	
	ZipDecorator zd(&fs); // Stream ��ü�� ���� ��� �߰�
	zd.Write("Hello");  // 1. Hello �� �����ϰ� <= �߰��� ���
						// 2. fs.Write()�� ����

	EncryptDecorator ed(&zd);
	ed.Write("hello");  // 1. hello �� ��ȣ�� �ϰ� <= �߰��� ���
						// 2. zd.Write()�� ����

	// FileStream �Ӿƴ϶� NetworkStream �� ��� Stream �� ���밡��
}
// Decorator			�����		
// ZipDecorator			FileStream
// EncryptDecorator		NetworkStream
//						PipeStream