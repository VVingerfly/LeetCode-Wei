/**
 * @file Q15_3Sum.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 三数之和
 * @version 0.1
 * @date 2021-01-24
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 三数之和
 *
 * 给你一个包含 `n` 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 * 示例 1：
 * - 输入：nums = [-1,0,1,2,-1,-4]
 * - 输出：[[-1,-1,2],[-1,0,1]]
 *
 * 示例 2：
 * - 输入：nums = []
 * - 输出：[]
 *
 * 示例 3：
 * - 输入：nums = [0]
 * - 输出：[]
 *  
 * 提示：
 * - `0 <= nums.length <= 3000`
 * - `-105 <= nums[i] <= 105`
 *
 * @note: https://leetcode-cn.com/problems/3sum
 *
 */
class A11_3Sum
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> results;
        int count = nums.size();
        if (count < 3)
            return results;

        vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());  // 首先对数组进行排序

        for (int i = 0; i < count; i++) {
            int num1 = sorted_nums[i];
            if (num1 > 0)  // 所有数字均大于0，其和不可能为0
                break;
            if (i > 0 && num1 == sorted_nums[i - 1])  // 去重
                continue;

            int i_left = i + 1;
            int i_right = count - 1;
            while (i_left < i_right) {
                int sum = num1 + sorted_nums[i_left] + sorted_nums[i_right];
                // printf("%d %d %d %d\n", i, i_left, i_right, sum);
                if (sum == 0) {
                    results.push_back(std::vector<int>{ num1, sorted_nums[i_left], sorted_nums[i_right] });
                    // break;
                    while (i_left < i_right && sorted_nums[i_left] == sorted_nums[i_left + 1])
                        i_left++;  // 去重
                    while (i_left < i_right && sorted_nums[i_right] == sorted_nums[i_right - 1])
                        i_right--;  // 去重
                    i_left++;
                    i_right--;
                }
                if (sum > 0)  // 当前和大于0，从右侧较大的数往左，找较小一点的数重新计算三数之和
                    i_right--;
                if (sum < 0)  // 当前和小于0，从左侧较小的数往右，找较大一点的数重新计算三数之和
                    i_left++;
            }
        }
        return results;
    }
};

int main()
{
    vector<vector<int>> nums = { { -1, 0, 1, 2, -1, -4 }, {}, { 0 }, { 0, 0, 0, 0 } };
    vector<vector<vector<int>>> results = { { { -1, -1, 2 }, { -1, 0, 1 } }, {}, {}, { { 0, 0, 0 } } };

    auto is_equal = [results](const vector<vector<int>>& res, const vector<vector<int>>& sol) {
        if (res.empty() && sol.empty())
            return true;
        if (sol.size() != res.size())
            return false;
        for (int i = 0; i < sol.size(); ++i) {
            if (sol[i].empty() && res[i].empty())
                return true;
            if (sol[i].size() != res[i].size())
                return false;
            for (int j = 0; j < sol[i].size(); ++j) {
                if (sol[i][j] != res[i][j])
                    return false;
            }
        }
        return true;
    };
    auto print = [](const vector<vector<int>>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j)
                cout << " " << nums[i][j];
            cout << endl;
        }
    };


    A11_3Sum solution;
    for (size_t i = 0; i < nums.size(); i++) {
        vector<vector<int>> res = solution.threeSum(nums[i]);
        if (is_equal(res, results[i]))
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result:" << endl;
            print(res);
            cout << "Expected Result:" << endl;
            print(results[i]);
        }
    }

    return 0;
}
