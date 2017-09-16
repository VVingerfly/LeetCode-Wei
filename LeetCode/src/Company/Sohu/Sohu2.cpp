#include "SohuDefs.h"
#include <iostream>
#include <string>
using namespace std;

/**
* @brief Use brief, otherwise the index won't have a brief explanation.
*
* Detailed explanation.
* @note
* @see
*/
class CSohu2
{
public:
	/*!
	* @brief ������кϷ����������

	* ����N�����ţ���������еĺϷ������״̬��
	* ���磬n=3�����еĺϷ�״̬Ϊ��"((()))��, ��(()())��, ��(())()��, ��()(())��, ��()()()����\n
	* ����������DFS��˼·�����ѵĹ��̹ؼ����ڼ�¼�Ѿ��õ��������Ÿ����������ŵĸ�����
	* ���ù��������Ÿ���С����������Ƿ��������߸����ʹ���2N��Ƿ��������߸����������Ŀ����2N��Ϊ�Ϸ���
	* @param n ��������Ŷ���
	* @return NULL
	* @note ����������h(n)= h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)h(0) (����n>=1)������h��0��=1
	* @see http://blog.csdn.net/keshacookie/article/details/44937777 \n
	*      http://blog.csdn.net/ffmpeg4976/article/details/42340379 \n
	*
	*/
	void legalBrackets(int n)
	{
		str_brackets.resize(2 * n);
		solve(n, 0, 0);
	}

	void solve(int n, int ls, int rs)
	{
		if (ls == rs && ls + rs == 2 * n)
		{
			cout << str_brackets << endl;
			return;
		}
		if (ls < rs || ls + rs >= 2 * n) return;
		int index = ls + rs;
		str_brackets[index] = '(';
		solve(n, ls + 1, rs);
		str_brackets[index] = ')';
		solve(n, ls, rs + 1);
	}


	string str_brackets; /*!< string that store the legal brackets */

	void runTest()
	{
		legalBrackets(3);
	}
};



#ifdef RUN_Sohu2
int main()
{
	CSohu2 res;
	res.runTest();
	return 0;
}
#endif


