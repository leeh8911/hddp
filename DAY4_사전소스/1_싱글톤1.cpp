// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
// => 오직 한개의 객체만 존재
// => 어디서든 동일한 방법으로 객체에 접근 (Cursor::getInstance())

// 싱글톤 패턴에 대한 좋지 않은 시선 : 
// => 결국 전역 변수!!!! (전역 변수는 좋지 않음)

// 싱글톤을 구현하는 방법은 아주 다양함!
// 아래 처럼 "static 지역 변수"로 구현 하는 모양
// => effective-C++ 의 저자인 "scott-meyer"가 처음으로 제안
// => "Meyer's Singleton"
class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}
	// 규칙 2. 복사 생성자와 대입 연산자도 "컴파일러가 자동으로 생성할 수 없게 해야 함"
	// C++98 시절
	// => 사용자가 "private 영역"에 "선언만" 만든다
	// 1. 사용자가 선언했으므로 컴파일러는 제공 안함.
	// 2. 복사 생성자를 사용하는 코드가 없으면 문제 없음
	// 3. 복사 생성자를 사용하는 코드가 있으면 "링크 에러" - 결국 복사될 수 없음
//private:
//	Cursor(const Cursor& c);
//	Cursor& operator=(const Cursor& c);

	// C++11 이후
	// 위 기술의 의도는 "컴파일러가 복사 생성자를 만들지 못하게" 하려는 의도
	// C++11 부터는 함수 삭제 문법 사용
private:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
	// 복사 생성자를 삭제하면, 관례적으로 대입 연산자도 삭제함
	
	// 규칙 3. 오직 한개의 객체를 생성해서 반환하는 "static 멤버 함수"
public:
	static Cursor& getInstance() {
		static Cursor instance;
		return instance;
	}

};


int main()
{
	Cursor& c1 = Cursor::getInstance(), &c2 = Cursor::getInstance();

	std::cout << "C1 객체 주소 : " << &c1 << std::endl;
	std::cout << "C2 객체 주소 : " << &c2 << std::endl;

	// Cursor c3 = c1; // "복사 생성자" 호출
						// 이렇게 만드는 것도 할 수 없게 해야 함
						// 복사 생성자를 삭제하면 Error!
}








