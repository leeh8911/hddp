// ��� 2. ���ϴ� ���� �ٸ� Ŭ������
//  => "strategy(����) ����"

// ���� : ����ȭ ��å���� �ϳ��� Ŭ������ ĸ��ȭ �ߴ�.
//       List �Ӿƴ϶� �پ��� Ŭ�������� ��밡���ϴ�.

// ���� : �������̽� ��� �̹Ƿ� "�����Լ�" �̴�. 
//       ������ ȣ�� �Ǹ� ������.!

struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

template<typename T> class List
{
	ISync* pSync = nullptr;
public:
	void setSync(ISync* p) { pSync = p; }

	void push_front(const T& a)
	{
		if (pSync != nullptr) pSync->lock();
 		//...... next, prev ���� ��� ����
		if (pSync != nullptr) pSync->unlock();
	}
};
//-----------------
// �پ��� ����ȭ ����� ����ȭ ��å�� ���� ��å Ŭ���� ����
#include <mutex>

class mutex_locker : public ISync
{
	std::mutex m;
public:
	void lock() override   { m.lock(); }
	void unlock() override { m.unlock(); }
};

List<int> st;

int main()
{
	mutex_locker m;
	st.setSync(&m); // ����ȭ ��å ����
	st.push_front(10);
}




