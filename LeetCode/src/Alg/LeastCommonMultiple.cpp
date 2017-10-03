#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief ������������С��������
 *
 * ������շ��������������������Լ������С��������������֮���������Լ����
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

	int gcd_recursive(int a, int b) //a,b���Լ�����ݹ�
	{
		if (b == 0)
			return a;
		else
			return gcd_recursive(b, a%b);
	}

	int lcm(int a, int b) //��С������
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