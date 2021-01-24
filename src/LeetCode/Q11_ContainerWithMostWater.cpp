/**
 * @file Q11_ContainerWithMostWater.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 寻找两个正序数组的中位数
 * @version 0.1
 * @date 2021-01-24
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)
 * 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 说明：你不能倾斜容器。
 *
 * 示例 1：
 * - 输入：[1,8,6,2,5,4,8,3,7]
 * - 输出：49
 * - 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 *
 * 示例 2：
 * - 输入：height = [1,1]
 * - 输出：1
 *
 * 示例 3：
 * - 输入：height = [4,3,2,1,4]
 * - 输出：16
 *
 * 示例 4：
 * - 输入：height = [1,2,1]
 * - 输出：2
 *  
 * 提示：
 * - `n = height.length`
 * - `2 <= n <= 3 * 104`
 * - `0 <= height[i] <= 3 * 104`
 *
 * @note: https://leetcode-cn.com/problems/container-with-most-water
 *
 */
class A11_ContainerWithMostWater
{
public:
    int maxArea(vector<int>& height)
    {
        int count = height.size();
        if (count <= 1)
            return 0;

        int i_left = 0;
        int i_right = count - 1;
        int max_area = 0;
        int cur_area = 0;
        while (true) {
            // cout << i_left << " " << i_right << " " << cur_area << " " << max_area << endl;
            cur_area = std::min(height[i_left], height[i_right]) * (i_right - i_left);
            max_area = std::max(max_area, cur_area);
            // 寻找下一个更高的木板，由于左右木板之间的距离变近，只有更高的木板才有可能围出更大的面积
            // 尝试将当前左右木板中较矮的那个替换掉
            if (height[i_left] < height[i_right]) {
                // 左边木板高度比右边低，从左边往右继续找下一个更高的木板
                int i = i_left;
                for (; i <= i_right; ++i) {
                    if (height[i] > height[i_left]) {
                        i_left = i;  // 找到更高的木板，返回计算更新面积
                        break;
                    }
                }
                // cout << "-->" << i << " " << i_left << " " << i_right << endl;
                if (i - 1 == i_right)  // 从左往右找不到更高的目标，这里i+1而不是i是因为上面的for语句的++i
                    break;
            }
            else {
                // 右边木板高度比左边低，从右边往左继续找下一个更高的木板
                int i = i_right;
                for (; i >= i_left; --i) {
                    if (height[i] > height[i_right]) {
                        i_right = i;  // 找到更高的木板，返回计算更新面积
                        break;
                    }
                }
                // cout << "++>" << i << " " << i_left << " " << i_right << endl;
                if (i + 1 == i_left)  // 从右往左找不到更高的目标，这里i+1而不是i是因为上面的for语句的++i
                    break;
            }

            if (i_left >= i_right) {
                break;
            }
        }
        return max_area;
    }
};

int main()
{
    vector<vector<int>> heights = { { 1, 8, 6, 2, 5, 4, 8, 3, 7 }, { 1, 1 }, { 4, 3, 2, 1, 4 }, { 1, 2, 1 } };
    vector<int> results = { 49, 1, 16, 2 };
    A11_ContainerWithMostWater solution;
    for (size_t i = 0; i < heights.size(); i++) {
        int res = solution.maxArea(heights[i]);
        if (res == results[i])
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result: " << res << endl;
            cout << "Expected Result: " << results[i] << endl;
        }
    }

    return 0;
}
