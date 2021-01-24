//============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Jun/11 22:43:47
// Last Change  : 2017/Jun/11 22:43:59
// Summary      :
//============================================================

/****************************************************************
Description:
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

Difficulty : Hard
******************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 正则表达式匹配
 * 
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 *
 * 示例 1：
 * - 输入：s = "aa" p = "a"
 * - 输出：false
 * - 解释："a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * - 输入：s = "aa" p = "a*"
 * - 输出：true
 * - 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 示例 3：
 * - 输入：s = "ab" p = ".*"
 * - 输出：true
 * - 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 示例 4：
 * - 输入：s = "aab" p = "c*a*b"
 * - 输出：true
 * - 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 示例 5：
 * - 输入：s = "mississippi" p = "mis*is*p*."
 * - 输出：false
 *
 * 提示：
 * - `0 <= s.length <= 20`
 * - `0 <= p.length <= 30`
 * - `s` 可能为空，且只包含从 `a-z` 的小写字母。
 * - `p` 可能为空，且只包含从 `a-z` 的小写字母，以及字符 `.` 和 `*`。
 * - 保证每次出现字符 * 时，前面都匹配到有效的字符
 *
 * @note: https://leetcode-cn.com/problems/regular-expression-matching
 *
 */
class A10_RegExpMatching
{
public:
    bool isMatch(string s, string p) 
    { 
        if (p.empty())
            return true;
        if (s.empty())
            return false;
        
        return true; 
    }
};

int main()
{
    vector<pair<string, string>> strs = { {"aa", "a"}, {"aa", "a*"}, {"ab", ".*"}, {"aab", "c*a*b"}, {"mississippi", "mis*is*p*."}};
    vector<bool> rlts = {false, true, true, true, false};

    A10_RegExpMatching solution;
    for (size_t i = 0; i < strs.size(); i++)
    {
        int res = solution.isMatch(strs[i].first, strs[i].second);
        if (res == rlts[i]) cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result: " << res << endl;
            cout << "Expected Result: " << rlts[i] << endl;
        }
    }
    return 0;
}
