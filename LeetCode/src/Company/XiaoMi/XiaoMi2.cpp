
#include "XiaoMiDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief ����һ�������Ľ׳ˣ�ע�⣺��������������
 *
 * **����**\n
 * ����һ��������
 *
 * **���**\n
 * ���һ��������
 *
 * ��������
 * ```
 * 3
 * 10
 * ```
 * �������
 * ```
 * 6
 * 3628800
 * ```
 * @note 
 * @see 
 */
class XiaoMi2
{
public:
	unsigned long long res(unsigned long long n)
	{
		if (n == 1) return 1;
		return n*res(n - 1);
	}

};




#ifdef RUN_XiaoMi2

int main()
{
	XiaoMi2 mi2;
	unsigned long long n;
	cin >> n;
	cout << mi2.res(n) << endl;
}

#endif // RUN_XiaoMi2