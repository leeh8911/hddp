#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� �и�
// 2. ���ϴ� ���� �ٸ� Ŭ������ �и� - ���ؾ� �ϹǷ� ��ü�� �����ؾ� �Ѵ�.
//								- �������̽� ����� ���� ������ ����ؾ� �Ѵ�.

// ��� validation ��å�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; };

	virtual ~IValidator() {}
};
// �ֹ� ��Ϲ�ȣ : 9211 1     Ȯ��

class Edit
{
	std::string data;
	
	IValidator* pVal = nullptr;
public:
	void setValidator(IValidator* p) { pVal = p; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pVal == nullptr || pVal->iscomplete(data))   ) break;

			if ( pVal == nullptr || pVal->validate(data,c) ) // ���� ��ȿ�� Ȯ���� �ܺ��� 
			{							  // �ٸ� ��ü�� ����.
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};




int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



