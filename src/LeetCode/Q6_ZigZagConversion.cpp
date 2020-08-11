/**
 * @file Q6_ZigZagConversion.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief
 * @version 0.1
 * @date 2017-03-22
 *
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * @brief Z字形变换
 * 
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * ```
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * ```
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows)
 * 
 * 示例 1:
 * 
 * - 输入: s = "LEETCODEISHIRING", numRows = 3
 * - 输出: "LCIRETOESIIGEDHN"
 * 
 * 示例 2:
 * - 输入: s = "LEETCODEISHIRING", numRows = 4
 * - 输出: "LDREOEIIECIHNTSG"
 * 
 *   解释:
 *   ```
 *   L     D     R
 *   E   O E   I I
 *   E C   I H   N
 *   T     S     G
 *   ```
 * 
 * @note https://leetcode-cn.com/problems/zigzag-conversion
 * 
 */
class A6_ZigZagConversion
{
    // 0123456789
    // A     G     M
    //  B   F H   L
    //   C E   I K
    //    D     J
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) {
            return s;
        }
        vector<pair<int, int>> sortStr;
        int cntRows = 0;
        int cntCols = 0;
        bool goDown = true;
        for (cntCols = 0; cntCols < s.length(); ++cntCols) {
            sortStr.push_back(make_pair(cntRows, cntCols));

            goDown ? cntRows++ : cntRows--;
            if (goDown && cntRows == numRows) {
                cntRows--;
                cntRows--;
                goDown = false;
                continue;
            }
            if (!goDown && cntRows == -1) {
                cntRows++;
                cntRows++;
                goDown = true;
                continue;
            }
        }

        // printSortStr(sortStr, s);
        string sOut;
        for (int row = 0; row < numRows; ++row) {
            for (int i = 0; i < sortStr.size(); ++i) {
                if (sortStr.at(i).first == row) {
                    sOut += s.at(sortStr.at(i).second);
                }
            }
        }

        return sOut;
    }
    string convert2(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        
        // 0      | 6        | 12        18
        // 1    5 | 7     11 | 13     17
        // 2  4   | 8  10    | 14  16
        // 3      | 9        | 15 
        // 一组有cnt=(numRows-1)*2=6个数
        // 每一纵列的偏移是cnt=6
        // 除去首尾两行，中间行的多出的一个数相对其纵列的偏移是cnt-2*r

        string sOut;
        sOut.reserve(s.length());
        int len = s.length();
        int cnt = (numRows-1) * 2;
        int numCols = len / cnt;
        if (cnt * numCols < len) numCols++;
        for (int r = 0; r < numRows; r++)
        {
            for (int c = 0; c < numCols; c++)
            {
                int id = r + c * cnt;
                int id1 = -1;
                if (r > 0 && r < numRows-1) id1 = id + cnt - r * 2;
                if (id < len) sOut += s[id];
                if (id1 != -1 && id1 < len) sOut += s[id1];
            }
        }
        return sOut;
    }
};

int main()
{
    vector<pair<string, int>> strs = { {"LEETCODEISHIRING", 3}, {"LEETCODEISHIRING", 4}, {"PAYPALISHIRING", 3}};
    vector<string> rlts = {"LCIRETOESIIGEDHN", "LDREOEIIECIHNTSG", "PAHNAPLSIIGYIR"};
    for (int i = 0; i < strs.size(); ++i)
    {
        auto s = strs[i];
        A6_ZigZagConversion solution;
        // string res = solution.convert(s.first, s.second);
        string res = solution.convert2(s.first, s.second);
        cout << ((res == rlts[i]) ? "Pass" : "Failed") << endl; 
        cout << "  result   : " << res << endl;
        cout << "  solution : " << rlts[i] << endl;
    }
    
    return 0;
}
