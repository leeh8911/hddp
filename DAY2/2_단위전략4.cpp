// ��� 3. ��å Ŭ���� ��ü�� "�������̽�" �� �ƴ� "���ø� ���ڷ�"

// �������̽��� ����Ѵٴ� ���� "�����Լ�"�� ����Ѵٴ� �ǹ�
/*
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};
*/


template<typename T, typename ThreadModel > class List
{
	ThreadModel tm;
public:

	void push_front(const T& a)
	{
		tm.lock();

		//...... next, prev ���� ��� ����

		tm.unlock();
	}
};

//-----------------
// �پ��� ����ȭ ����� ����ȭ ��å�� ���� ��å Ŭ���� ����
#include <mutex>

class mutex_locker 
{
	std::mutex m;
public:
	inline void lock()    { m.lock(); }
	inline void unlock()  { m.unlock(); }
};
class nolock
{
public:
	inline void lock() { }
	inline void unlock() {  }
};

List<int, nolock>       st;
List<int, mutex_locker> st2;

int main()
{
	st.push_front(10);
}




