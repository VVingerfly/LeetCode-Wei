/**
 * @file Q22_GenerateParentheses.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 括号生成
 * @version 0.1
 * @date 2021-02-28
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;


/**
 * @brief 括号生成
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。
 *
 * 示例 1：
 * - 输入：n = 3
 * - 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 * 示例 2：
 * - 输入：n = 1
 * - 输出：["()"]
 *
 * 提示：
 * - `1 <= n <= 8`
 *
 * @note https://leetcode-cn.com/problems/generate-parentheses
 */
class A22_GenerateParentheses
{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
    
    /**
     * @brief 
     * 
     * @param [in] res 
     * @param [in] str 
     * @param [in] l 使用的左括号 ( 的数量
     * @param [in] r 使用的右括号 ) 的数量
     * @param [in] n 总数量
     */
    void generate(vector<string> &res, string str, int l, int r, int n){
        if(l > n || r > n)  // 左括号或右括号已使用完
            return;
        if (r > l)  // 剩余右括号的数量大于左括号的数量
            return;
        if(l == n && r == n) {  // 左右括号刚好使用完毕
            res.push_back(str);
            return;
        }
        generate(res, str + '(', l+1, r, n);  // 使用左括号
        generate(res, str + ')', l, r+1, n);  // 使用右括号
        return;
    }
};

int main()
{
    vector<int> nums = { 3, 1, 4 };
    vector<vector<string>> results = { 
        { "((()))", "(()())", "(())()", "()(())", "()()()" }, 
        { "()" },
        {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"}
    };
    auto compare_vector = [](const vector<string>& v1, const vector<string>& v2) {
        if (v1.size() != v2.size())
            return false;
        for (size_t i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < nums.size(); i++) {
        A22_GenerateParentheses solution;
        auto res = solution.generateParenthesis(nums[i]);

        cout << "Test case " << i + 1 << "/" << results.size() << " -> ";
        if (compare_vector(results[i], res))
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "  Returned Result: ";
            for (const auto& v : res)
                cout << v << " ";
            cout << endl;
            cout << "  Expected Result: ";
            for (const auto& v : results[i])
                cout << v << " ";
            cout << endl;
        }
    }
    return 0;
}
