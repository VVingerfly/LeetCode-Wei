//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Feb/13 11:00:30
// Last Change  : 2017/Feb/13 11:00:33
// Summary      :
//===============================================================

#pragma once
#include <string>
#include <iostream>
using std::endl;
using std::cout;
using std::string;

void testQ3();

class A3_LongestSubstring 
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int max_length = -1;
		string substr;
		for (int i = 0; i < s.length(); i++)
		{
			cout << i << endl;
			bool is_new_char = true;
			for (int j = 0; j < substr.length(); j++)
			{
				if (s.at(i) == substr.at(j))
				{
					is_new_char = false;
					break;
				}
			}
			if (is_new_char)
			{
				substr = substr + s.at(i);
			}
			else
			{
				cout << substr << "  " << substr.length() << " max " << max_length << endl;
				if (max_length < (substr.length()))
				{
					max_length = substr.length();
					cout << "max length here " << max_length << endl;
				}
				substr.clear();
				i--;
			}
		}
		if (1 < 2) cout << "2222";
		return max_length;
	}
};
