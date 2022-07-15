#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

// SRP(Single Responsiblity Principle)
// => ���� å���� ��Ģ
// => �ϳ��� Ŭ������ �ϳ��� å�Ӹ� �ִ°��� ���ٴ� �ǹ�.

class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. ��Ʈ��ũ ���̺귯�� �ʱ�ȭ
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket ���̺귯�� cleanup
		WSACleanup();
	}
};
// IP �ּҸ� �����ϴ� Ŭ����
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket �۾��� å������ Ŭ����
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP ������ �������
// => ��� Ŭ������ ����ؼ�
// => �־��� ������ ���ľ߸� ����� �ֽ��ϴ�.

// �� ������ �ѹ��� ���ִ� "���� ������ Ŭ����"�� �����մϴ�.

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM }; // TCP ����
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	// ���̺귯���� ���� ���� "TCPServer" �� �����Ѵٸ� 
	// ����ڴ� �Ʒ� ó�� ���� ���� �۾��Ҽ� �ֽ��ϴ�.
	TCPServer server;
	server.Start("127.0.0.1", 4000);


}