/*
С����һ�����۰����ߣ����Ҷ���һ����������Լ��ʮ�ָ���Ȥ��һ��С����������һ�����⣺ 
���庯��f(x)Ϊx��������Լ����xΪ�������� ����:f(44) = 11.
���ڸ���һ��N����Ҫ��� f(1) + f(2) + f(3).......f(N)
���磺 N = 7
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
С�׼�������������������ѣ���Ҫ�������һ���㷨��������
��������:
����һ������N (1 �� N �� 1000000000)

�������:
���һ����������Ϊf(1) + f(2) + f(3).......f(N)

��������:
7

�������:
21
*/
#pragma once


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int f(int x) // maximal odd yueshu
{
	for (int i = x; i > 0; --i)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		double r = x / (1.0*i);
		if (r - int(r) < 0.000001)
		{
			return i;
		}
	}
	return 1;
}

//#define RUN_NetEase6
#ifdef RUN_NetEase6
int main()
{
	int N;
	cin >> N;
	int res = 0;
	for (int i = 1; i < N + 1; i++)
	{
		res += f(i);
	}
	cout << res << endl;

	return 0;
}

#endif
