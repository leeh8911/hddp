// 7_�̱���1 - 123 page
#include <iostream>
#include <mutex>

// mutex ���� ����� ��, lock/unlock�� ���� �ϸ�, ���� ���� �߻� ��, "deadlock"�� ������ ����
// �׻� �ڿ� ������ "������/�Ҹ���"�� ����ؼ� �ڵ�ȭ �ؾ� ��
// �̷� ����� "RAII"��� �θ�

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
		// lock_guard<std::mutex> guard(mtx);	// �����ڿ��� mtx.lock() ����
											// �Ҹ��ڿ��� mtx.unlock() ����
		std::lock_guard<std::mutex> g(mtx);  // �̹� C++ ǥ�ؿ� ����...!!
		 
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