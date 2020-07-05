/**
 * @file Q3_LongestSubstring.cpp
 * @author Wei LI (lw15@mail.ustc.edu.cn)
 * @brief 无重复字符的最长子串
 * @version 0.1
 * @date 2017-02-13
 *
 */


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * @brief 无重复字符的最长子串
 * 
 * 给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。
 * 
 * 示例 1:
 * - 输入: "abcabcbb"
 * - 输出: 3 
 * - 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 示例 2:
 * - 输入: "bbbbb"
 * - 输出: 1
 * - 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 示例 3:
 * - 输入: "pwwkew"
 * - 输出: 3
 * - 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *   请注意，你的答案必须是 **子串** 的长度，"pwke" 是一个子序列，不是子串。
 *
 * @note https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 *
 */
class A3_LongestSubstring
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> char_map;  // 哈希表，key为字符串中字符，value为其下标索引的下一个
        int max_len = 0;
        int beg_idx = 0;  // 子串起始位置
        int end_idx = 0;  // 子串结尾位置
        while (true) {
            //std::cout << " " << beg_idx << "(" << s[beg_idx] << ") " << end_idx <<  "(" << s[end_idx] << ") " << max_len << endl;
            if (end_idx >= s.size())
                break;

            char c = s.at(end_idx);
            auto it = char_map.find(c);
            if (it != char_map.end())  // key已经存在
            {
                int pos = char_map.at(c);
                beg_idx = std::max(beg_idx, pos);  // 更新起始位置
            }
            char_map[c] = end_idx + 1;  // 更新map，key存在则更新value，不存在则插入。注意不要使用insert！
            max_len = std::max(max_len, end_idx - beg_idx + 1);
            end_idx++;
        }
        return max_len;
    }
};


int main()
{
    unordered_map<string, int> strs = { {"pwwkew", 3},  {"b", 1}, {"abcabcbb", 3}, {"dvdf", 3}};
    for (const auto& s : strs)
    {
        A3_LongestSubstring solution;
        int result = solution.lengthOfLongestSubstring(s.first);
        cout << "result=" << result << "  gt=" << s.second << " str=" << s.first << endl;
    }
    return 0;
}