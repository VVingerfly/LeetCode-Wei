/**
 * @file Q03.cpp
 * @author Wei LI (lw15@mail.ustc.edu.cn)
 * @brief 数组中重复的数字
 * @version 0.1
 * @date 2021-06-30
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

/**
 * @brief 数组中重复的数字
 *
 * @note https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
 *
 */
class A03
{
public:
    int findRepeatNumber(vector<int>& nums)
    {
        vector<int> counts(nums.size(), 0);  //记录每个数字出现的次数，初始均为0
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            counts[v]++;
            if (counts[v] > 1)
                return v;
        }
        return 0;
    }
};


int main()
{
    
    return 0;
}
