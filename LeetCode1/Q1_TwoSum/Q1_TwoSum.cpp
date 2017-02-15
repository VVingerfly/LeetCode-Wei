//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Jan/5 19:45:26
// Last Change  : 2017/Jan/5 19:45:29
// Summary      :
//===============================================================

#include "Q1_TwoSum.h"
#include <iostream>

void testQ1()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 13;

	A1_TwoSum solution;
	vector<int> result = solution.twoSum(nums, target);

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result.at(i) << " ";
	}
	std::cout << std::endl;
}

