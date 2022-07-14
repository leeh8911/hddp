// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

// mutex 등을 사용할 때, lock/unlock을 직접 하면, 예외 등이 발생 시, "deadlock"의 위험이 있음
// 항상 자원 관리는 "생성자/소멸자"를 사용해서 자동화 해야 함
// 이런 기술을 "RAII"라고 부름

template<typename T>
class lock_guard {
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard() { mtx.unlock(); }
};

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sInstance;
	static std::mutex mtx;

public:
	static Cursor& getInstance() {
		// lock_guard<std::mutex> guard(mtx);	// 생성자에서 mtx.lock() 수행
											// 소멸자에서 mtx.unlock() 수행
		std::lock_guard<std::mutex> g(mtx);  // 이미 C++ 표준에 있음...!!
		 
		if (sInstance == nullptr) {
			sInstance = new Cursor;
		}
		return *sInstance;
	}
};
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	Cursor& c3 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
	std::cout << &c3 << std::endl;
}