/*
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果


输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1

输入例子:
20

输出例子:
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
