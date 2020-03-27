/**
 * @file Q1_TwoSum.cpp
 * @author Wei LI (lw15@mail.ustc.edu.cn)
 * @brief
 * @version 0.1
 * @date 2017-01-02
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

/**
 * @brief 给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 **两个** 整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 示例:
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 *
 * @note https://leetcode-cn.com/problems/two-sum
 *
 */
class A1_TwoSum
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        res.resize(2, 0);
        unordered_map<int, int> numsHash;
        for (size_t i = 0; i < nums.size(); ++i) {
            int value1 = nums.at(i);
            auto it = numsHash.find(target - value1);
            if (it != numsHash.end()) {
                res[0] = i < it->second ? i : it->second;
                res[1] = i < it->second ? it->second : i;
                break;
            }
            numsHash.insert(std::make_pair(nums.at(i), i));  // if not found, store the <value, index> in hash for later searching
        }
        return res;
    }
};

int test(vector<int>& nums, int target, vector<int>& rlts)
{
    A1_TwoSum solution;
    vector<int> result = solution.twoSum(nums, target);
    for (int i = 0; i < result.size(); ++i)
        if (result[i] != rlts[i])
            return -1;
    return 0;
}

int main()
{
    // vector<int> nums = { 2, 7, 11, 15 };
    // int target = 9;
    // vector<int> nums = { 3, 2, 4 };
    // int target = 6;
    vector<int> nums = { 3, 3 };
    int target = 6;

    A1_TwoSum solution;
    vector<int> result = solution.twoSum(nums, target);

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << nums[result[0]] << " + " << nums[result[1]] << " = " << target << std::endl;

    return -1;
    return 0;
}
