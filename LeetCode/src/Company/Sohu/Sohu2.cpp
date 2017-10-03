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
	* @brief 输出所有合法的括号组合

	* 给定N对括号，输出其所有的合法的组合状态，
	* 例如，n=3，所有的合法状态为："((()))”, “(()())”, “(())()”, “()(())”, “()()()”；\n
	* 解析：深搜DFS的思路，深搜的过程关键在于记录已经用掉的左括号个数和右括号的个数，
	* 当用过的左括号个数小于右括号则非法；当二者个数和大于2N则非法；当二者个数相等且数目等于2N则为合法。
	* @param n 输入的括号对数
	* @return NULL
	* @note 卡特兰数：h(n)= h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)h(0) (其中n>=1)，而且h（0）=1
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


