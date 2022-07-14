// 7_싱글톤1 - 123 page
#include <iostream>
#include <mutex>

// github.com/aosp-mirror => android open source project의 약자
// platform_system_core 선택
// libutils/include/utils/singleton.h 열어보세요~

// CRTP : ㅊCuriously Recurring Template Pattern (C++ Idioms)
// => 기반 클래스 설계시 파생 클래스의 이름을 사용할 수 있게 하는 기술
// => 기반 클래스가 템플릿인데, 파생 클래스 만들 때 자신의 이름을 템플릿 인자로
//		전달하는 기술

template<typename TYPE>
class Singleton
{
protected:
	Singleton() {}

private:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static TYPE* sInstance;
	static std::mutex mtx;

public:
	static TYPE& getInstance() {
		std::lock_guard<std::mutex> g(mtx);

		if (sInstance == nullptr) {
			sInstance = new TYPE;
		}
		return *sInstance;
	}
};
template<typename TYPE>
TYPE* Singleton<TYPE>::sInstance = nullptr;

template<typename TYPE>
std::mutex Singleton<TYPE>::mtx;

// Keyboard 도 힙에 만드는 싱글톤 기법을 사용하고 싶다!
class Keyboard : public Singleton<Keyboard> {

};


int main()
{
	Keyboard& k = Keyboard::getInstance();
}