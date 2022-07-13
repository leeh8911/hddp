#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// ��� ������ Stream �� ������ �����ؾ� �Ѵ�.
// �������̽��� ���� �մϴ�.
class Stream
{
public:
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}

	// �׿ܿ� ��� Stream �� ������ Ư¡�� �����մϴ�.
	// bool isopen() {} ��..
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
		printf("%s ����\n", s.c_str() );
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");

//	NetworkStream ns("200.200.200.100", 4000);
//	ns.Write("hello");

//	PipeStream ps("named pipe");
//	ps.Write("hello");

}