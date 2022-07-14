// 7_객체생성정리 - 118 page
class Rect
{
};

// 객체를 만드는 방법

// 1. new Rect     => 가장 자유로운 방법

// 2. Rect::create()  : static 멤버 함수 사용
//						다양한 제약을 사용할수 있다.
//				A. 오직 한개만 만들수 있게 -> 싱글톤
//				B. 속성이 동일하면 공유    => 플라이 웨이트
//			    C. 생성함수주소를 함수 인자로 전달하거나
//				   자료구조에 보관

// 3. r->clone();  : 복사본을 사용한 객체 생성 - Prototype

// 4. factory.create() : 공장을 통한 객체 생성




