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
using namespace std;

class A10_RegExpMatching
{
public:
    bool isMatch(string s, string p) { return 0; }
};

void TestQ10()
{
    string s1 = "22";
    string p1 = "ss";
    string s = s1;
    string p = p1;
    A10_RegExpMatching solution;
    int res = solution.isMatch(s, p);
    cout << "input str : " << s << endl;
    cout << "solution  : " << res << endl;
}
