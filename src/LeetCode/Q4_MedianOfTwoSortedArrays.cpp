/**
 * @file Q4_MedianOfTwoSortedArrays.cpp
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
using namespace std;

/**
 * @brief 寻找两个正序数组的中位数
 * 
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 `nums1` 和 `nums2`。
 * 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 `nums1` 和 `nums2` 不会同时为空。
 * 
 * 示例 1:
 * - nums1 = [1, 3]
 * - nums2 = [2]
 * <br> 则中位数是 2.0
 * 
 * 示例 2:
 * - nums1 = [1, 2]
 * - nums2 = [3, 4]
 * <br> 则中位数是 (2 + 3)/2 = 2.5
 *
 * @note https://leetcode-cn.com/problems/median-of-two-sorted-arrays
 * @note https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
 */
class A4_MedianOfTwoSortedArrays
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int left = (len1 + len2 + 1) / 2;
        int right = (len1 + len2 + 2) / 2;
        //将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
        return (get_kth(nums1, 0, len1 - 1, nums2, 0, len2 - 1, left) + get_kth(nums1, 0, len1 - 1, nums2, 0, len2 - 1, right)) * 0.5;  
    }
    int get_kth(vector<int>& nums1, int bgn1, int end1, vector<int>& nums2, int bgn2, int end2, int k)
    {
        int len1 = end1 - bgn1 + 1;
        int len2 = end2 - bgn2 + 1;
        
        // 让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
        if (len1 > len2) return get_kth(nums2, bgn2, end2, nums1, bgn1, end1, k);
        if (len1 == 0) return nums2[bgn2 + k - 1];

        if (k == 1) return std::min(nums1[bgn1], nums2[bgn2]);

        int i = bgn1 + std::min(len1, k / 2) - 1;
        int j = bgn2 + std::min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j]) {
            return get_kth(nums1, bgn1, end1, nums2, j + 1, end2, k - (j + 1 - bgn2));
        }
        else {
            return get_kth(nums1, i + 1, end1, nums2, bgn2, end2, k - (i + 1 - bgn1));
        }
    }
};

int main()
{
    int n1[] = { 1, 2 };
    int n2[] = { 3, 4 };
    vector<int> nums1(n1, n1 + 2);
    vector<int> nums2(n2, n2 + 2);
    A4_MedianOfTwoSortedArrays solution;
    double res = solution.findMedianSortedArrays(nums1, nums2);
    cout << "solution: " << res << endl;
    return 0;
}
