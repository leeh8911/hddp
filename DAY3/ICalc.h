// ICalc.h
#pragma once

// �� ���� ������ ������ ������ ����ϴ� ���.
// ��� �������̽����� ������ �����ϴ� �Լ��� �ʿ� �ϰ� �ȴ�.
// ��� Ŭ����(�������̽�)�� �и�����

struct IRefCount
{
	// ��ü�� ������ ��������� �����ϰ�..
	// ���� ����(�������̽�)�� ����ؼ� ��ü�� ����ϱ�� �ߴٸ�
	// �������̽� �ȿ� �ݵ�� ��ü�� ������ �����ϴ� �Լ��� ������ ���ԵǾ�� �մϴ�
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};
struct ILed : public IRefCount
{
	virtual void LedOn() = 0;
	virtual void LedOff() = 0;
	virtual ~ILed() {}
};
