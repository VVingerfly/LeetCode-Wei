//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Feb/13 11:19:16
// Last Change  : 2017/Feb/13 11:19:19
// Summary      :
//===============================================================

#include "Q3_LongestSubstring.h"

void testQ3()
{
	string str1 = "pwwkew";

	string str = str1;
	A3_LongestSubstring solution;
	int result = solution.lengthOfLongestSubstring(str);
	cout << "input string: " << str << endl;
	cout << "length of longest substring: " << result << endl;
}