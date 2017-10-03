#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief �������������Լ����
 *
 * ŷ����ã�շת��������㷨��`m`��`n`���Լ����
 * r Ϊ m/n ����������gcd(m,n) = gcd(n,r) = ...��
 * r=0 ʱ n �� gcd
 * @see
*/
class AlgGCD
{
public:
	int gcd(int a, int b) 
	{
		int r;
		while (b!= 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}

	int gcd_recursive(int a, int b) //a,b���Լ�����ݹ�
	{
		if (b == 0)
			return a;
		else
			return gcd_recursive(b, a%b);
	}
};


#ifdef RUN_AlgGCD
int main()
{
	int a = 24;
	int b = 6;
	AlgGCD res;
	cout << res.gcd(a, b) << endl;
	cout << res.gcd_recursive(a, b) << endl;
	return 0;
}
#endif