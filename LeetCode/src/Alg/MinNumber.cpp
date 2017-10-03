#include "AlgDefs.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& str1, const string &str2)
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;
	return s1 < s2;
}

/**
 * @brief 把数组排成最小的数。
 *
 * 思路：先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。
 * 这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。
 * - 如果ab < ba，则a < b；
 * - 如果ab > ba，则a > b；
 * - 如果ab = ba，则a = b。
 
 * 比较函数的定义是本解决方案的关键。这道题其实就是希望我们能找到一个排序规则，根据这个规则排出来的数组能排成一个最小的数字。
 * @see
 - http://www.cnblogs.com/youxin/p/3294154.html
*/
class AlgMinNum
{
#define min(x,y) ((x<y)?x:y)
public:


	void ComArrayMin(const vector<int> &pArray)
	{
		int num = pArray.size();
		int i;
		string *pStrArray = new string[num];

		for (i = 0; i < num; i++)
		{
			pStrArray[i] = to_string(pArray[i]);
		}

		sort(pStrArray, pStrArray + num, compare);

		for (i = 0; i < num; i++)
			cout << pStrArray[i];
		cout << endl;
		delete[] pStrArray;

	}

	void runTest()
	{
		vector<int> pArray{ 321, 32 };
		ComArrayMin(pArray);
	}
	
};


#ifdef RUN_AlgMinNum
int main()
{

	AlgMinNum res;
	res.runTest();

	return 0;
}
#endif
