#include <iostream>
#include <string>
#include <conio.h>

// ����) �ϱ��Լ�(�Լ�������)�� validation �Լ��� �Ķ���ͷ� getData�� �ѱ�� ������� 
// �����ϴ� �� �� ��� �� �������?

class Edit
{
	std::string data;
	
	using VALIDATOR = bool(*)(char); // �Լ�������Ÿ��
	
	VALIDATOR validate = nullptr; // �Լ� ������ ����
public:
	void setValidator(VALIDATOR val) { validate = val; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if ( validate == nullptr || validate(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl;
		return data;
	}
};

bool validate(char c) { return isdigit(c); }


int main()
{
	Edit e;
	e.setValidator(&validate);

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}



