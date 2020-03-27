//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Mar/22 19:47:48
// Last Change  : 2017/Mar/22 19:47:50
// Summary      :
//===============================================================

/****************************************************************
Description:
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:
    string convert(string text, int nRows);

Example:
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Difficulty : Medium
******************************************************************/

#include <iostream>
#include <string>
using namespace std;

void printSortStr(const vector<pair<int, int>>& sortStr, string s)
{
    for (size_t i = 0; i < sortStr.size(); ++i) {
        cout << i << " " << s.at(i) << " : " << sortStr.at(i).first << " " << sortStr.at(i).second << endl;
    }
}

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
};

int main()
{
    string str1 = "PAYPALISHIRING";
    string str2 = "bbb";
    string str3 = "cbbd";
    string str4 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string str = str1;
    int numRows = 3;
    A6_ZigZagConversion solution;
    string res = solution.convert(str, numRows);
    cout << "input str : " << str << endl;
    cout << "solution  : " << res << endl;
    return 0;
}
