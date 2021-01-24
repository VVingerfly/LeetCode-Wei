/**
 * @file Q14_LongestCommonPrefix.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 最长公共前缀
 * @version 0.1
 * @date 2020-10-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief 最长公共前缀
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * - 输入: ["flower","flow","flight"]
 * - 输出: "fl"
 * 
 * 示例 2:
 * - 输入: ["dog","racecar","car"]
 * - 输出: ""
 * - 解释: 输入不存在公共前缀。
 * 
 * 说明: 所有输入只包含小写字母 a-z 。
 * 
 * @note https://leetcode-cn.com/problems/longest-common-prefix
 *
 */
class A14_LongestCommonPrefix
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string();
        if (strs.size() == 1) return strs[0];

        int i = 0;  //字符串的第i个字符
        bool is_same;
        while (true) {
            is_same = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].length()) {  // 达到最短字符串的最大长度，终止
                    is_same = false;
                    break;
                }
                if (strs[j][i] != strs[0][i]) {  // 当前字符不相等，终止
                    is_same = false;
                    break;
                }
            }
            if (is_same)
                i++;  //第i个字符相等，判断下一个字符
            else 
                break;
        }
        return strs[0].substr(0, i);
    }

};

int main()
{
    vector<vector<string>> strs = {{{"flower","flow","flight"}, {"dog","racecar","car"}}};
    vector<string> rlts = {{"fl"}, {""}};

    for (size_t i = 0; i < strs.size(); i++)
    {
        A14_LongestCommonPrefix solution;
        string res = solution.longestCommonPrefix(strs[i]);
        if (res == rlts[i]) cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result: " << res << endl;
            cout << "Expected Result: " << rlts[i] << endl;
        }
    }
    return 0;
}
