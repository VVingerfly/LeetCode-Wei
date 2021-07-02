/**
 * @file Q5_LongestPalindromicSubstring.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 最长回文子串
 * @version 0.1
 * @date 2017-03-22
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 最长回文子串
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 * - 输入: "babad"
 * - 输出: "bab"
 * <br> 注意: "aba" 也是一个有效答案。
 *
 * 示例 2：
 * - 输入: "cbbd"
 * - 输出: "bb"
 *
 * @note https://leetcode-cn.com/problems/longest-palindromic-substring
 *
 */
class A5_LongestPalindromicSubstring
{
public:
    string longestPalindrome(string s)
    {
        // 从中间向两端出发，比较两侧的字符来判断以该中心点的最大回文字符
        // 计算每个字符的最大回文字符串
        // 在每两个字符之间插入特殊字符来避免奇偶分类问题 aba 与 aa
        // aba -> a#b#a
        // aa  -> a#a
        string str;  // string after insert # in s
        str.reserve(2 * s.length());
        for (int i = 0; i < s.length(); ++i) {
            str += s.at(i);
            if (i + 1 == s.length())
                break;
            str += "#";
        }
        // cout << "input str = " << s << endl;
        // cout << "new str   = " << str << endl;
        int len_max = 0;  // length of longest palindrome
        int pos_max = 0;  // position of longest palindrome
        int str_len = str.length();
        for (int i = 0; i < str_len; ++i) {
            int len_half = 0;
            while (true)  // find palindrome in str with middle char i
            {
                if (i - len_half < 0 || i + len_half >= str_len)
                    break;
                if (str.at(i - len_half) != str.at(i + len_half))
                    break;
                len_half++;
            }
            len_half--;
            // cout << i << " " << lenHalf << " substr = " << str.substr(i - lenHalf, 2 * lenHalf + 1) << endl;

            int len_i = 0;
            int pos_i = 0;
            if (str.at(i) == '#')  // calculate the len and pos of maximal palindrome in input string s
            {
                                                      //  b # a # a # b        
                len_i = 2 * ((len_half + 1) / 2);     //  0 1 2 3 4 5 6
                pos_i = i / 2 - len_i / 2 + 1;        //  0   1   2   3
            }
            else {
                                                     //   b # a # b
                len_i = 2 * (len_half / 2) + 1;      //   0 1 2 3 4
                pos_i = i / 2 - len_i / 2;           //   0   1   2
            }
            // cout << "  " << i << " " << str.at(i) << " len = " << len_i << " pos = " << pos_i << endl;
            if (len_max < len_i) {
                len_max = len_i;
                pos_max = pos_i;
            }
        }
        return s.substr(pos_max, len_max);
    }
};

int main()
{
    vector<string> strs = {"babad", "bbb", "cbbd"};
    for (size_t i = 0; i < strs.size(); i++)
    {
        A5_LongestPalindromicSubstring solution;
        string res = solution.longestPalindrome(strs[i]);
        cout << "-------- " << i << endl;
        cout << "input str : " << strs[i] << endl;
        cout << "solution  : " << res << endl;
    }
    return 0;
}
