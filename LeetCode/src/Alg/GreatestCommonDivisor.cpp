#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief 求两个数的最大公约数。
 *
 * 欧几里得（辗转相除法）算法求`m`和`n`最大公约数。
 * r 为 m/n 的余数，则gcd(m,n) = gcd(n,r) = ...，
 * r=0 时 n 即 gcd
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

	int gcd_recursive(int a, int b) //a,b最大公约数，递归
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