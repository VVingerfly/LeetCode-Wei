/*
С��ȥ�������̵���ƻ������թ���̷�ʹ���������ף�ֻ�ṩ6��ÿ����8��ÿ���İ�װ(��װ���ɲ��)�� 
����С������ֻ�빺��ǡ��n��ƻ����С���빺�����ٵĴ�������Я����������ܹ���ǡ��n��ƻ����С�׽����Ṻ��
��������:
����һ������n����ʾС���빺��n(1 �� n �� 100)��ƻ��


�������:
���һ��������ʾ������Ҫ����Ĵ��������������ǡ��n��ƻ�������-1

��������:
20

�������:
3
*/

#pragma once
#include "../../global.h"

#ifdef RUN_NetEase7

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int buyApple(int n) // maximal odd yueshu
{
	int n8 = n / 8;
	if (n % 8 == 0)
	{
		return n8;
	}
	//for (int i = 0; i < n8+1; ++i)
	for (int i = n8; i > -1; --i)
	{
		int r = n - 8 * i;
		if ( r % 6 == 0)
		{
			return i + r / 6;
		}
	}
	return -1;
}


int main()
{
	int N;
	cin >> N;
	cout << buyApple(N) << endl;

	return 0;
}

#endif
