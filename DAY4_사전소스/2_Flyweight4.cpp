#include <iostream>

int main() {
	char s1[] = "hello"; // 문자열 배열
	// char* s2 = "hello";  // 문자열 포인터

	// C 언어
	// char* s2 = "hello"; // ok
	//*s2 = 'A'; //runtime error. 상수 메모리를 변경하려고 함

	// C++ 언어
	// char* s2 = "hello"; // error
	const char* s2 = "hello"; // ok
	// *s2 = 'A'; // compile error (runtime error 아님)
				// const 를 변경하려고 하므로 컴파일 오류 발생

	printf("%p\n", s1); // 스택에 놓인 배열의 주소
	printf("%p\n", s2); // 상수 메모리를 가리키는 포인터가 갖는 주소

	// 핵심
	char ss1[] = "hello";
	char ss2[] = "hello";

	const char* ss3 = "hello";
	const char* ss4 = "hello";

	// 아래 4개의 주소를 생각해 보세요!
	printf("%p\n", ss1);
	printf("%p\n", ss2);
	printf("%p\n", ss3); // ss3, ss4는 같은 주소를 공유 (flyweight!)
	printf("%p\n", ss4);

}