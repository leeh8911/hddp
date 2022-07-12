// ��� 3. ��å Ŭ���� ��ü�� "�������̽�" �� �ƴ� "���ø� ���ڷ�"


// ��å Ŭ������ ��ü �ϴ� 2���� ���
// 1. �������̽� ������� ��ü : "strategy" ����
// 2. ���ø� ���ڷ� ��ü      : "policy base design"

// ����� - �� ������ ������

//				strategy			policy base
// �ӵ�			�����Լ����(������)	�ζ��� �Լ�(������.)
// ����ð� ��ü	����ð� ��ü ����		����ð��� ��ü �Ҽ� ����.
//				setSync(�ٸ���å)

// �׷���, List �� ����ȭ ���θ� "����ð��� ��ü" ������ ����.

// Policy Base Design ���� ��å Ŭ������ "�ݵ�� ���Ѿ��ϴ±�Ģ"�� �ְ� �Ǵ�.
// => �Ʒ� List �� ����ȭ ��å�� �ݵ�� "lock/unlock"�� �ʿ��ϴ�.
// => �������̽��� ������ �����Ƿ�, "����ȭ" �ؾ� �Ѵ�.
//    �̷� ������ "named requirement" ��� �մϴ�.

// ����!! ���� "STL" �� list�� "�Ʒ� ó�� �Ǿ����� �ʽ��ϴ�."
// => 1998 �� ����ô� "����ȭ�� ������� �ʰ� ������" 
// => ����ڰ� ���� ����ȭ �ؾ� �մϴ�.


// �������̽��� ����Ѵٴ� ���� "�����Լ�"�� ����Ѵٴ� �ǹ�
/*
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};
*/


template<typename T, typename ThreadModel = nolock> class List
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

//List<int, nolock>       st;
List<int>       st;
List<int, mutex_locker> st2;

int main()
{
	st.push_front(10);
}




