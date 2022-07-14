// 7_�̱���1 - 123 page
#include <iostream>
#include <mutex>

// github.com/aosp-mirror => android open source project�� ����
// platform_system_core ����
// libutils/include/utils/singleton.h �������~

// CRTP : ��Curiously Recurring Template Pattern (C++ Idioms)
// => ��� Ŭ���� ����� �Ļ� Ŭ������ �̸��� ����� �� �ְ� �ϴ� ���
// => ��� Ŭ������ ���ø��ε�, �Ļ� Ŭ���� ���� �� �ڽ��� �̸��� ���ø� ���ڷ�
//		�����ϴ� ���

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

// Keyboard �� ���� ����� �̱��� ����� ����ϰ� �ʹ�!
class Keyboard : public Singleton<Keyboard> {

};


int main()
{
	Keyboard& k = Keyboard::getInstance();
}