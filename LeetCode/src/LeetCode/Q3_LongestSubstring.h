//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Feb/13 11:00:30
// Last Change  : 2017/Feb/13 11:00:33
// Summary      :
//===============================================================

#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
using std::endl;
using std::cout;
using std::string;
using std::unordered_map;


class A3_LongestSubstring 
{
public:
	int lengthOfLongestSubstring(string s)
	{


		unordered_map<char, int> subStr0;
		subStr0['v'] = 1;
		subStr0['d'] = 2;
		subStr0['f'] = 3;
		auto iter0 = subStr0.begin();
		while (iter0 != subStr0.end())
		{
			cout << iter0->first << "  " << iter0->second << endl;
			iter0++;
		}
		cout << "-------------------------------" << endl;
		unordered_map<string, int> subStr1;
		subStr1.emplace(std::make_pair("v", 1));
		subStr1.emplace(std::make_pair("d", 2));
		subStr1.emplace(std::make_pair("f", 3));
		auto iter = subStr1.begin();
		while (iter != subStr1.end())
		{
			cout << iter->first << "  " << iter->second << endl;
			iter++;
		}
		cout << "-------------------------------" << endl;
		return 0;

		unordered_map<char, int> subStr;
		size_t maxLength = 0;
		size_t beginIdx = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			char c = s.at(i);
			auto it = subStr.find(c);
			if (it != subStr.end())  // already exist in hash
			{
				size_t len = subStr.size();
				if (len > maxLength)
				{
					maxLength = subStr.size(); 
					beginIdx = subStr.begin()->second;
					cout << " --- " << s.substr(beginIdx, maxLength) << " --- " << endl;
				}
				i = subStr.begin()->second;
				subStr.clear();
				continue;
			}
			subStr[c] = i;
			//subStr.insert(std::make_pair(c, i));
			if (i+1 == s.size() && subStr.size() > maxLength)
			{
				beginIdx = subStr.begin()->second;
				maxLength = subStr.size();
			}
		}
		string resStr = s.substr(beginIdx, maxLength);
		cout << "result string : " << resStr << endl;
		return maxLength;
	}
};


void TestQ3()
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