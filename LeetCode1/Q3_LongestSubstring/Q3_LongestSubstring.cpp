//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Feb/13 11:19:16
// Last Change  : 2017/Feb/13 11:19:19
// Summary      :
//===============================================================

#include "Q3_LongestSubstring.h"
#define DEBUG_Q3

void testQ3()
{
	string str1 = "pwwkew";
	string str2 = "b";
	string str3 = "abcabcbb";
	string str4 = "dvdf";

	string str = str4;
	A3_LongestSubstring solution;
	int result = solution.lengthOfLongestSubstring(str);
	cout << "input string: " << str << endl;
	cout << "length of longest substring: " << result << endl;
}

#ifdef DEBUG_Q3
int main()
{
	testQ3();
	return 0;
}
#endif