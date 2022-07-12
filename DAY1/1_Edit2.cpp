#include <iostream>
#include <string>
#include <conio.h>

// ���� 28 page ~ 

// Edit �� ���� �Ҷ��� ����ڰ� Validation ��å�� �����Ҽ� �ְ� ���� �Ǿ�� �մϴ�
// ��� 1. 
class Edit
{
	std::string data;
public:
	// �ٽ� 1. ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� ã�Ƽ� �и��Ѵ�.
	// => ���ϴ� �κ��� �����Լ��� �и��Ѵ�.
	virtual bool validate(char c)
	{
		return true;
	}
	
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (validate(c)) // ���ϴ� �κ��� "�����Լ�ȣ��" �� 
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};

// ���� validation ��å�� �����Ϸ��� "Edit"�� ���� �Ļ� �� Ŭ������ �����մϴ�
// => ���� Ŭ����(Edit) �� ������ �ƴ�
// => Edit �� Ȯ���� ���� ����� ����
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



