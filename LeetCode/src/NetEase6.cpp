/*
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 
定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。
输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)

输出描述:
输出一个整数，即为f(1) + f(2) + f(3).......f(N)

输入例子:
7

输出例子:
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
