// 37 page

template<typename T> class List
{
	// member data....
public:
	void push_front(const T& a)
	{
		// ��� 2. ��� �Լ� �ȿ��� ����ȭ �Ѵ�.(thread-safe class )
		mutex.lock();
		//...... next, prev ���� ��� ����
		mutex.unlock();
	}
};
List<int> st; // ���������� ��Ƽ�����忡 �������� �ʽ��ϴ�.

int main()
{
	// ��� 1. ��� �Լ� ȣ��� ����ȭ �ϰų�. 
//	mutex.lock();
	st.push_front(10);
//	mutex.unlock();
}




