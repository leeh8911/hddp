// 7_ΩÃ±€≈Ê1 - 123 page
#include <iostream>
#include <mutex>

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
		mtx.lock();
		if (sInstance == nullptr) {
			sInstance = new Cursor;
		}
		mtx.unlock();
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