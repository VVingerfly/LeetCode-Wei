
#pragma once
#include "../global.h"

#ifdef CNOTE1

#include <iostream>
/**
 * @brief ��Ա�����ĳ�ʼ��˳��ֻ������������������˳���йأ����ڳ�ʼ���б��е�˳���޹ء�
 *
 * @note ��C++�У���Ա�����ĳ�ʼ��˳��\bֻ������������������˳���й�>������<b>�ڳ�ʼ���б��е�˳���޹�</b>��\n
 * �����У�n1����n2���������n1Ҳ����n2֮ǰ��ʼ������������n2+2��ʼ��n1����ʱn2��ֵ������ģ�
 * ��n1Ҳ��һ�����ֵ��Ȼ����0��ʼ��n2.
 */
class CNote1
{
private:
	int n1;
	int n2;

public:
	CNote1() : n2(0), n1(n2 + 2) {}
	CNote1(int n) { n2 = n; n1 = n2 + 2; }
	void Print() { std::cout << "n1: " << n1 << ", n2: " << n2 << std::endl; }
};

int main()
{
	CNote1 a;
	a.Print();
	CNote1 b(0);
	b.Print();
	return 0;
}

#endif