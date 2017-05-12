//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Jan/5 19:46:00
// Last Change  : 2017/Jan/5 19:46:03
// Summary      : Use hash(unordered_map) for quick find operation
//===============================================================

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class A1_TwoSum 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> res;
		res.resize(2, 0);
		unordered_map<int, int> numsHash;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			int value1 = nums.at(i);
			auto it = numsHash.find(target - value1);
			if (it != numsHash.end())
			{
				res[0] = i < it->second ? i : it->second;
				res[1] = i < it->second ? it->second : i;
				break;
			}
			numsHash.insert(std::make_pair(nums.at(i), i));  // if not found, store the <value, index> in hash for later searching
		}
		return res;
	}
};

void TestQ1()
{
	//vector<int> nums = { 2, 7, 11, 15 };
	//int target = 9;
	//vector<int> nums = { 3, 2, 4 };
	//int target = 6;
	vector<int> nums = { 3, 3 };
	int target = 6;

	A1_TwoSum solution;
	vector<int> result = solution.twoSum(nums, target);

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << nums[result[0]] << " + " << nums[result[1]] << " = " << target << std::endl;

}
