//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Mar/22 10:29:59
// Last Change  : 2017/Mar/22 10:30:05
// Summary      :
//===============================================================

/****************************************************************
Description:
	Given a string s, find the longest palindromic substring in s. 
	You may assume that the maximum length of s is 1000.

Example:
	Input: "babad"
	Output: "bab"
	Note: "aba" is also a valid answer.
Example:
	Input: "cbbd"
	Output: "bb"

Difficulty : Medium
******************************************************************/

#ifndef Q5_LongestPalindromicSubstring_h__
#define Q5_LongestPalindromicSubstring_h__

#include <iostream>
#include <string>
using namespace std;


class A5_LongestPalindromicSubstring
{
public:
	string longestPalindrome(string s)
	{
		// 从中间向两端出发，比较两侧的字符来判断以该中心点的最大回文字符
		// 计算每个字符的最大回文字符串
		// 在每两个字符之间插入特殊字符来避免奇偶分类问题 aba 与 aa
		// aba -> a#b#a
		// aa  -> a#a

		string str;  // string after insert # in s
		for (int i = 0; i < s.length(); ++i)
		{
			str += s.at(i);
			if (i+1 == s.length())
			{
				break;
			}
			str += "#";
		}
		//cout << "input str = " << s << endl;
		//cout << "new str   = " << str << endl;
		int len_max = 0;
		string str_res;
		int str_len = str.length();
		for (int i = 0; i < str_len; ++i)
		{
			int lenHalf = 0;
			while (true)  // find palindrome in str with middle char i
			{
				if (i - lenHalf < 0 || i + lenHalf >= str_len)
				{
					break;
				}
				//cout << " " << i << " " << lenHalf << " : " << str.at(i - lenHalf) << " = " << str.at(i + lenHalf) << endl;
				if (str.at(i - lenHalf) != str.at(i + lenHalf))
				{
					break;
				}
				lenHalf++;
			}
			lenHalf--;
			//cout << i << " " << lenHalf << " substr = " << str.substr(i - lenHalf, 2 * lenHalf + 1) << endl;

			int len_i = 0;
			int pos_i = 0;
			if (str.at(i) == '#')  // calculate the len and pos of maximal palindrome in input string s
			{
				len_i = 2 * ((lenHalf + 1) / 2);   //   b#a#a#b
				if (len_i != 0)
				{
					pos_i = (i - 1) / 2 - len_i / 2 + 1;
				}
			}
			else
			{
				len_i = 2 * (lenHalf / 2) + 1;     //   b#a#b
				pos_i = i / 2 - len_i / 2;
			}
			//cout << "  " << i << " " << str.at(i) << " len = " << len_i << " pos = " << pos_i << endl;
			if (len_max < len_i)
			{
				len_max = len_i;
				str_res = s.substr(pos_i, len_i);
			}
			//cout << endl;
		}

		return str_res;
	}
};

void TestQ5()
{
	string str1 = "babad";
	string str2 = "bbb";
	string str3 = "cbbd";
	string str = str3;
	A5_LongestPalindromicSubstring solution;
	string res = solution.longestPalindrome(str);
	cout << "input str : " << str << endl;
	cout << "solution  : " << res << endl;
}


#endif // Q5_LongestPalindromicSubstring_h__
