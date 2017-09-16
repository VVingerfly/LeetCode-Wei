#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief 求两个数的最小公倍数。
 *
 * 先利用辗除法或其它方法求得最大公约数，最小公倍数等于两数之积除以最大公约数。
 * @see
*/
class AlgLCM
{
public:
	int gcd(int m, int n)
	{
		int r;
		while (n != 0)
		{
			r = m % n;
			m = n;
			n = r;
		}
		return m;
	}

	int gcd_recursive(int a, int b) //a,b最大公约数，递归
	{
		if (b == 0)
			return a;
		else
			return gcd_recursive(b, a%b);
	}

	int lcm(int a, int b) //最小公倍数
	{
		return a*b / gcd(a, b);
	}
};


#ifdef RUN_AlgLCM
int main()
{
	int a = 24;
	int b = 6;
	AlgLCM res;
	cout << res.lcm(a, b) << endl;
	return 0;
}
#endif