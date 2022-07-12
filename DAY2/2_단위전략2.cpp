
// ��� 1. ������ ����ȭ ���θ� template method�� ��ü �����ϰ�..
//	=> ���ϴ� ���� ���� �Լ���.

// => ����ȭ ���δ� ������ Ŭ�������� �ʿ� �ϴ�.
// => �׷���, template method �� "����ȭ ��å"�� �ٸ� Ŭ�������� ����Ҽ� ����.
//    (������ ����)

template<typename T> class List
{
	// member data....
public:
	void push_front(const T& a)
	{
		lock();
		//...... next, prev ���� ��� ����
		unlock();
	}
	// �⺻ ������ ����ȭ ����.
	virtual void lock() {}
	virtual void unlock() {}
};
// �� �ڵ��� �ǵ� : ����ȭ �ϰ� �ʹٸ� List �Ļ� Ŭ������ �����ؼ�
//					lock/unlock �� �������ؼ� ����ȭ ����� �����ض�!
#include <mutex>

template<typename T> class ThreadSafeList : public List<T>
{
	std::mutex m;
public:
	void lock()   override { m.lock(); }
	void unlock() override { m.unlock(); }
};

//List<int> st; 
ThreadSafeList<int> st;


int main()
{
	st.push_front(10);
}




