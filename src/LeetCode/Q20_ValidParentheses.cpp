/**
 * @file Q20_ValidParentheses.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 有效的括号
 * @version 0.1
 * @date 2021-02-24
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;


/**
 * @brief 有效的括号
 * 
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 1. 左括号必须用相同类型的右括号闭合。
 * 2. 左括号必须以正确的顺序闭合。
 * 
 * 示例 1：
 * - 输入：s = "()"
 * - 输出：true
 * 
 * 示例 2：
 * - 输入：s = "()[]{}"
 * - 输出：true
 * 
 * 示例 3：
 * - 输入：s = "(]"
 * - 输出：false
 * 
 * 示例 4：
 * - 输入：s = "([)]"
 * - 输出：false
 * 
 * 示例 5：
 * - 输入：s = "{[]}"
 * - 输出：true
 * 
 * 提示：
 * - `1 <= s.length <= 104`
 * - s 仅由括号 '()[]{}' 组成
 *
 * @note https://leetcode-cn.com/problems/valid-parentheses
 */
class A20_ValidParentheses
{
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        stack<char> parentheses;
        for (size_t i = 0; i < s.length(); i++) {
            if (parentheses.empty()) {
                parentheses.push(s[i]);
                continue;
            }
            // cout << parentheses.top() << " " << s[i] << endl;
            
            //有效情况下，栈中存储的应该都是左半括号
            //得到一对匹配的括号，从栈中弹出当前匹配到的括号
            if (pairs.find(s[i]) != pairs.end() && pairs.at(s[i]) == parentheses.top()) {
                parentheses.pop();
                continue;
            }
            parentheses.push(s[i]);
        }
        // cout << parentheses.size() << endl;

        if (!parentheses.empty())
            return false;  //栈不为空，说明有未被匹配到的括号
        return true;
    }
};

int main()
{
    vector<string> samples = {"()", "()[]{}", "(]", "([)]", "{[]}", "(){}}{"};
    vector<bool>   results = { true, true, false, false, true, false};

    for (size_t i = 0; i < samples.size(); i++) {
        A20_ValidParentheses solution;
        bool res = solution.isValid(samples[i]);
        
        cout << "Test case " << i + 1 << "/" << samples.size() << " -> ";
        if (res == results[i])
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "  Returned Result: " << res << endl;
            cout << "  Expected Result: " << results[i] << endl;
        }
    }
    return 0;
}
