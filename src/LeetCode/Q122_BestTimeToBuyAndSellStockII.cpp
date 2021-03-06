/**
 * @file Q122_BestTimeToBuyAndSellStockII.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 买卖股票的最佳时机 II
 * @version 0.1
 * @date 2020-10-19
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
 * @brief 买卖股票的最佳时机 II
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 
 * **注意**：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * - 输入: [7,1,5,3,6,4]
 * - 输出: 7
 * - 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
 * 
 * 示例 2:
 * - 输入: [1,2,3,4,5]
 * - 输出: 4
 * - 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
 * - 注意: 你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 * 
 * 示例 3:
 * - 输入: [7,6,4,3,1]
 * - 输出: 0
 * - 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 提示：
 * - `1 <= prices.length <= 3 * 10 ^ 4`
 * - `0 <= prices[i] <= 10 ^ 4`
 * 
 * @note https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
 *
 */
class A122_BestTimeToBuyAndSellStockII
{
public:
    int maxProfit(vector<int>& prices) {
        return 0;
    }

};

int main()
{
    vector<vector<int>> prices = {{7,1,5,3,6,4}, {1,2,3,4,5}, {7,6,4,3,1}};
    vector<int> rlts = {7, 4, 0};
    for (size_t i = 0; i < prices.size(); i++)
    {
        A122_BestTimeToBuyAndSellStockII solution;
        int res = solution.maxProfit(prices[i]);
        if (res == rlts[i]) cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result: " << res << endl;
            cout << "Expected Result: " << rlts[i] << endl;
        }
    }
    return 0;
}
