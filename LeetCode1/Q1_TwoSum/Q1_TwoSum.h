//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Jan/5 19:46:00
// Last Change  : 2017/Jan/5 19:46:03
// Summary      :
//===============================================================

#pragma once
#include <vector>
using std::vector;

void testQ1();

class A1_TwoSum 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> res;
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if ((nums.at(j) == target - nums.at(i)))
				{
					res.push_back(i);
					res.push_back(j);
					return res;
				}
			}
		}
		return res;
	}
};

