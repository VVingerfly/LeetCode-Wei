/*
A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C. ���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C�����ﱣ֤���ֻ��һ������A,B,C������������������
��������:
����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������
��Χ����-30��30֮��(������)��


�������:
���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո�
�������������������A��B��C�������No

��������:
1 -2 3 4

�������:
2 1 3
*/
#pragma once


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int candyNum(int a, int b, int c, int d, int *res) 
{
	int A2 = a + c;
	if (A2 % 2 != 0)
	{
		return -1;
	}
	res[0] = A2 / 2;
	int B2 = b + d;
	if (B2 % 2 != 0)
	{
		return -1;
	}

	res[1] = B2 / 2;
	res[2] = d - res[1];
	if (res[0]-res[1] != a || res[1] - res[2] != b || res[0] + res[1] != c || res[1] + res[2] != d)
	{
		return -1;
	}
	return 1;
}

//#define RUN_NetEase8
#ifdef RUN_NetEase8
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int res[3] = { 0, 0, 0 };
	if (candyNum(a, b, c, d, res) == 1)
	{
		cout << res[0] << " " << res[1] << " " << res[2] << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	

	return 0;
}

#endif
