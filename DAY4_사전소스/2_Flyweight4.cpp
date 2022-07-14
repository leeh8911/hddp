#include <iostream>

int main() {
	char s1[] = "hello"; // ���ڿ� �迭
	// char* s2 = "hello";  // ���ڿ� ������

	// C ���
	// char* s2 = "hello"; // ok
	//*s2 = 'A'; //runtime error. ��� �޸𸮸� �����Ϸ��� ��

	// C++ ���
	// char* s2 = "hello"; // error
	const char* s2 = "hello"; // ok
	// *s2 = 'A'; // compile error (runtime error �ƴ�)
				// const �� �����Ϸ��� �ϹǷ� ������ ���� �߻�

	printf("%p\n", s1); // ���ÿ� ���� �迭�� �ּ�
	printf("%p\n", s2); // ��� �޸𸮸� ����Ű�� �����Ͱ� ���� �ּ�

	// �ٽ�
	char ss1[] = "hello";
	char ss2[] = "hello";

	const char* ss3 = "hello";
	const char* ss4 = "hello";

	// �Ʒ� 4���� �ּҸ� ������ ������!
	printf("%p\n", ss1);
	printf("%p\n", ss2);
	printf("%p\n", ss3); // ss3, ss4�� ���� �ּҸ� ���� (flyweight!)
	printf("%p\n", ss4);

}