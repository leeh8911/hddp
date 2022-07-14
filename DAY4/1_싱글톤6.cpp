#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern (C++ IDioms)

// => ��� Ŭ���� ����� �Ļ� Ŭ������ �̸��� ����Ҽ� �ְ� �ϴ� ���
// => ��� Ŭ������ ���ø� �ε�, �Ļ� Ŭ���� ���鶧 �ڽ��� �̸��� ���ø� ���ڷ�
//    �����ϴ� ���

template<typename TYPE>
class Singleton
{
protected:
	Singleton() {}

private:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex mtx;
	static TYPE* sInstance;  // <<=====
public:
	static TYPE& getInstance() // <====
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (sInstance == nullptr)
		{
			sInstance = new TYPE;  // <===
		}
		return *sInstance;
	}
};
template<typename TYPE> std::mutex Singleton<TYPE>::mtx;
template<typename TYPE> TYPE* Singleton<TYPE>::sInstance = nullptr;


// Keyboard �� ���� ����� �̱��� ����� ����ϰ� �ʹ�.
class Keyboard : public Singleton< Keyboard >
{

};



int main()
{
}








