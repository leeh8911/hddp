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
//------------------------
// �پ��� Stream �� Stream �� ��� �߰� ��ü�� ������ ��� Ŭ���� �ʿ�
// => Stream ���� ���� �Ļ�..

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override
	{
		std::string s2 = s + " �����"; // �߰��� ���(����) ������

		stream->Write(s2);			   // stream ��ü ����
	}
};
class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s) override
	{
		std::string s2 = s + " ��ȣȭ"; 
		stream->Write(s2);			   
	}
};



int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello"); 

	ZipDecorator zd(&fs); 
	zd.Write("Hello");  
						

	EncryptDecorator ed(&zd);
	ed.Write("hello");  
						
}
