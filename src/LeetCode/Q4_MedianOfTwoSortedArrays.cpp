//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Mar/21 12:44:05
// Last Change  : 2017/Mar/21 12:44:08
// Summary      :
//===============================================================

/**************************************************************************
Description:
    There are two sorted arrays nums1 and nums2 of size m and n respectively.
    Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
Example 1 :
    nums1 = [1, 3]
    nums2 = [2]
    The median is 2.0
Example 2 :
    nums1 = [1, 2]
    nums2 = [3, 4]
    The median is(2 + 3) / 2 = 2.5
Difficulty : Hard
***************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class A4_MedianOfTwoSortedArrays
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        size_t i1 = 0;
        size_t len1 = nums1.size();
        size_t i2 = 0;
        size_t len2 = nums2.size();
        if (len1 == 0 && len2 == 0) {
            return 0;
        }
        if (len1 == 0) {
            return len2 % 2 == 0 ? 0.5 * (nums2.at(len2 / 2 - 1) + nums2.at(len2 / 2)) : nums2.at(len2 / 2);
        }
        if (len2 == 0) {
            return len1 % 2 == 0 ? 0.5 * (nums1.at(len1 / 2 - 1) + nums1.at(len1 / 2)) : nums1.at(len1 / 2);
        }
        vector<int> numsSort;
        while (true) {
            if (nums1.at(i1) < nums2.at(i2)) {
                numsSort.push_back(nums1.at(i1));
                i1++;
            }
            else {
                numsSort.push_back(nums2.at(i2));
                i2++;
            }
            if (i1 == len1 || i2 == len2)
                break;
        }

        cout << i1 << "  " << len1 << endl;
        cout << i2 << "  " << len2 << endl;
        for (; i1 < len1; ++i1)
            numsSort.push_back(nums1.at(i1));
        for (; i2 < len2; ++i2)
            numsSort.push_back(nums2.at(i2));

        for (size_t i = 0; i < numsSort.size(); ++i) {
            cout << numsSort.at(i) << " ";
        }
        cout << endl;

        int len = numsSort.size();
        if (len % 2 == 0) {
            return 0.5 * (numsSort.at(len / 2 - 1) + numsSort.at(len / 2));
        }
        else {
            return numsSort.at(len / 2);
        }
        return 0;
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
