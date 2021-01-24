/**
 * @file Q350_IntersectionOfTwoArraysII.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 寻找两个正序数组的中位数
 * @version 0.1
 * @date 2017-03-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/**
 * @brief 两个数组的交集 II
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 *
 * 示例 1：
 * - 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * - 输出: [2,2]
 *
 * 示例 2：
 * - 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * - 输出: [4,9]
 *
 * 说明：
 * - 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
 * - 我们可以不考虑输出结果的顺序。
 * 
 * 进阶：
 * - 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * - 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * - 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 * 
 * @note https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
 *
 */
class A350_IntersectionOfTwoArraysII
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 假设nums1长度更短
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> nums1_map;  // 记录每个数字出现的次数
        for (const auto& v : nums1)
            nums1_map[v]++;
        
        vector<int> res;
        for (const auto& v : nums2) {
            if (nums1_map.count(v) && nums1_map[v] > 0) {  // 如果nums1_map还存有相同值且次数大于0，则是相同元素
                res.push_back(v); 
                nums1_map[v]--;   // 数字次数减一
            }
        }
        return res;
    }

    vector<int> intersect_sort(vector<int>& nums1, vector<int>& nums2) {
        // 假设nums1长度更短
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        // 对两者排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // 依次判断数字是否相等
        vector<int> res;
        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums2[j] < nums1[i]) j++;
            else if (nums2[j] > nums1[i]) i++;
            else {
                res.push_back(nums2[j]);
                i++; j++;
            }
        }
        return res;
    }
};

int main()
{
    auto compare_vector = [](const vector<int>& v1, const vector<int>& v2) {
        if (v1.size() != v2.size())
            return false;
        auto v1_sort = v1; sort(v1_sort.begin(), v1_sort.end());
        auto v2_sort = v2; sort(v2_sort.begin(), v2_sort.end());
        for (size_t i = 0; i < v1_sort.size(); i++)
            if (v1_sort[i] != v2_sort[i]) return false;
        return true;
    };

    vector<vector<int>> nums1 = {{1,2,2,1}, {4,9,5}, {4,9,5,4,4}};
    vector<vector<int>> nums2 = {{2,2}, {9,4,9,8,4}, {9,4,9,8,4,6}};
    vector<vector<int>> rlts = {{2,2}, {4,9}, {9,4,4}};

    for (size_t i = 0; i < nums1.size(); i++)
    {
        A350_IntersectionOfTwoArraysII solution;
        // vector<int> res = solution.intersect(nums1[i], nums2[i]);
        vector<int> res = solution.intersect_sort(nums1[i], nums2[i]);
        if (compare_vector(res, rlts[i])) cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result: "; for (const auto& v : res) cout << v << " "; cout << endl;
            cout << "Expected Result: "; for (const auto& v : rlts[i]) cout << v << " "; cout << endl;
        }
    }
    return 0;
}
