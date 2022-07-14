#include <iostream>

int main()
{
	char s1[] = "hello";	// ���ڿ� �迭, sizeof(s1) => 6
//	char* s2 = "hello";		// ���ڿ� ������ sizeof(s1) => 4

	// C ���
//	char* s2 = "hello"; // ok.. (const ��� ����)
//	*s2 = 'A'; // runtime error. ����޸𸮸� �����Ϸ��� �Ѵ�.


	// C++ ���
//	char* s2 = "hello"; // error

	const char* s2 = "hello"; // ok
//	*s2 = 'A';  // compile error ( runtime error �ƴ�)
			    // const �� �����Ϸ��� �ϹǷ� �����Ϸ��� ���� �߻�

	printf("%p\n", s1); // ���ÿ� ���� �迭�� �ּ�
	printf("%p\n", s2); // ��� �޸𸮸� ����Ű�� �����Ͱ� ���� �ּ�..


	// �ٽ�
	char ss1[] = "hello";
	char ss2[] = "hello";

	const char* ss3 = "hello";
	const char* ss4 = "hello";

	// �Ʒ� 4���� �ּҸ� ������ ������.. ���� �ּҰ� ������� ?
	printf("%p\n", ss1);
	printf("%p\n", ss2);
	printf("%p\n", ss3);
	printf("%p\n", ss4);
}












