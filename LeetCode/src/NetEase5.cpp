/*
����һ������X���������rev(X)Ϊ��X����λ��ת����������ȥ����ǰ��0������:
��� X = 123����rev(X) = 321;
��� X = 100����rev(X) = 1.
���ڸ�������x��y,Ҫ��rev(rev(x) + rev(y))Ϊ���٣�
��������:
����Ϊһ�У�x��y(1 �� x��y �� 1000)���Կո������

�������:
���rev(rev(x) + rev(y))��ֵ

��������:
123 100

�������:
223
*/
#pragma once


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int revNum(int x)
{
	string s = to_string(x);
	reverse(s.begin(), s.end());
	return stod(s.c_str());
}

//#define RUN_NetEase5
#ifdef RUN_NetEase5
int main()
{
	int x, y;
	cin >> x >> y;
	cout << revNum(revNum(x) + revNum(y)) << endl;

	return 0;
}

#endif
