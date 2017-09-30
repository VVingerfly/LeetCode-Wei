
#include "XiaoMiDefs.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 序列模式匹配
 *
 * **题目描述：**\n
 * 给定文本text和待匹配字符串pattern，二者皆只包含小写字母，并且不为空。
 * 在text中找出匹配pattern的最短字符串，匹配指按序包含pattern，但不要求pattern连续。
 * 如text为abaacxbcbbbbacc，pattern为cbc，text中满足条件的是abaacxbcbbbbacc红色部分。

 * **输入**\n
 * 每行一个text和一个pattern，用空格分隔
 *
 * **输出**\n
 * 输出最短匹配序列起止位置，用空格分隔。若无满足条件的答案，则起止均为-1

 * **样例输入**
 * ```
 * abaacxbcbbbbacc cbc
 * abc x
 * aaabcac ac
 * ```
 * **样例输出**
 * ```
 * 4 7
 * -1 -1
 * 5 6
 * ```
 * @note To be finished.
 * @see 
 */
class XiaoMi1
{
public:
	int subStrCount(string str, string substr)
	{
		int index = -1;
		int count = 0;
		while (index = str.find(substr, index + 1), index != string::npos)
		{
			count++;
		}
		return count;
	}


	void runTest()
	{

	}
};


#ifdef RUN_XiaoMi1

int main()
{
	XiaoMi1 mi1;
	mi1.runTest();
	return 0;
}

#endif // RUN_XiaoMi1