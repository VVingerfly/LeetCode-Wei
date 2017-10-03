
#include "XiaoMiDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief ·���滮��쳲��������У�
 *
 * **��Ŀ������**\n
 * ���Ӵ�A�ص�B�أ�����ÿ1������һ����Ϣվ��
 * ��������ÿ��������������2���Ҳ����˵���ӿ���ѡ������1�������2���������Ϣ��Ȼ�����ǰ����
 * ����A�ص�B�ؾ���N��������ӵ�������Ϣ�����ж�����(ÿһ�������һ��)��
 * ��ע���ɲ�����������������⣬�������������֤������2^31��
 * 
 * **����**\n
 * ����һ�����ͣ���ʾA�ص�B�صľ���
 *
 * **���**\n
 * ���һ�����ͣ���ʾ���߷�����Ŀ
 * 
 * **��������**\n
 * ```
 * 0
 * 1
 * 2
 * 5
 * ```
 * **�������**\n
 * ```
 * 1
 * 1
 * 2
 * 8
 * ```
 * @note 
 * @see 
 */
class XiaoMi3
{
public:
	unsigned long long recursive(int n)
	{
		if (n == 0) return 1;
		if (n <= 2) return n;
		return recursive(n - 1) + recursive(n - 2);
	}

	unsigned long long iterative(int n)
	{
		if (n == 0) return 1;
		if (n <= 2) return n;

		int f1 = 1, f2 = 2, f3;
		for (int i = 3; i <= n; ++i)
		{
			f3 = f2 + f1;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}

	unsigned long long m3(unsigned n)
	{
		//if (n == 0) return 1;
		//if (n <= 2) return n;

		double sum = 0, tmp1, tmp2;
		int i, j;

		for (i = 0; i <= n / 2; i++)
		{
			tmp1 = tmp2 = 1;
			for (j = 0; j < i; j++)
			{
				tmp1 *= (n - i - j);
				tmp2 *= (i - j);
			}
			sum += (tmp1 / tmp2);
		}

		return (unsigned long long)(sum);
	}

	void runTest()
	{
		int x = 100;
		for (int i = 0; i < x; i++)
		{
			cout << i;
			//cout << "  " << recursive(i);
			cout << "  " << iterative(i);
			//cout << "  " << m3(i);
			cout << endl;
		}
	}
};


#ifdef RUN_XiaoMi3

int main()
{
	XiaoMi3 mi3;
	int n;
	cin >> n;
	cout << mi3.recursive(n) << endl;
	cout << mi3.iterative(n) << endl;
	return 0;
}

#endif // RUN_XiaoMi3





