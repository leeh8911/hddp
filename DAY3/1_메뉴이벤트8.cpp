// 1_�޴��̺�Ʈ8 - 5�� �����ϼ���
#include <iostream>
#include <algorithm>
#include <functional> 
using namespace std::placeholders; 

void foo(int a, int& b)
{
    b = 100;
}
int main()
{
    int n = 0;

    std::function<void(int)> f;

//  f = std::bind(&foo, _1, n); // n�� ���� ������ ������ �����մϴ�.
    f = std::bind(&foo, _1, std::ref(n)); // n�� ������ ������ �޶�.


    f(5); // foo(5, n) �ϱ� ?  foo(5, 0) �ϱ� ?

    std::cout << n << std::endl;

}

