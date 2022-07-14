#include <iostream>
#include <mutex>

// mutex ���� ����Ҷ�, lock/unlock �� ���� �ϸ�
// ���� ���� �߻��� "deadlock" �� ������ �ֽ��ϴ�.

// �׻� �ڿ� ������ "������/�Ҹ���"�� ����ؼ� �ڵ�ȭ �ؾ� �մϴ�
// �̷� ����� "RAII" ��� �θ��ϴ�.

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
};



class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* sInstance;
public:


	static Cursor& getInstance()
	{
//		lock_guard<std::mutex> g(mtx);  // �����ڿ��� mtx.lock() ����
										// �Ҹ��ڿ��� mtx.unlock() 
										// 
		std::lock_guard<std::mutex> g(mtx); // �̹� C++ ǥ�ؿ� �ֽ��ϴ�

	//	mtx.lock();		
		if (sInstance == nullptr)
		{
			sInstance = new Cursor;
		}
		//	mtx.unlock();


		return *sInstance;
	}


};
std::mutex Cursor::mtx;
Cursor* Cursor::sInstance = nullptr;




int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








