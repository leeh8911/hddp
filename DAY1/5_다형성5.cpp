// 5_������5.cpp
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f1() {}
	virtual void f2() {}
};

class Derived : public Base {
public:
	void f1() override {}
	void f2() override final {}
	// �ڽ� Ŭ������ �� �̻� �������̵��� �Ұ����ϵ��� �մϴ�.
};

class DerivedDerived : public Derived {
public:
	void f1() override {}
	// void f2() override {}
};