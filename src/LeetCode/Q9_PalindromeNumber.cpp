//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Apr/3 20:42:06
// Last Change  : 2017/Apr/3 20:42:10
// Summary      :
//===============================================================

/****************************************************************
Description:
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.

Difficulty : Easy
******************************************************************/

#include <iostream>
#include <string>
using namespace std;

class A9_PalindromeNumber
{
public:
    bool isPalindrome(int x)
    {
        // int [-2147483648, 2147483647]
        if (x == -2147483648) {
            return false;
        }
        if (x < 0) {
            return false;
            x = -x;
        }
        if (x == 0) {
            return true;
        }

        string invStr;
        int cnt = 0;
        int x_orig = x;
        while (x >= 10) {
            cnt++;
            int y = x % 10;
            invStr += std::to_string(y);
            x = x / 10;
        }
        invStr += std::to_string(x);
        string origStr = std::to_string(x_orig);
        cout << "inv " << invStr << endl;
        cout << "src " << origStr << endl;
        if (origStr == invStr) {
            return true;
        }
        return false;

        return 0;
    }
};

void TestQ9()
{
    int x1 = 123444;
    int x2 = 123321;
    int x3 = -2147483648;
    int x4 = -2147447412;
    int x = x4;
    A9_PalindromeNumber solution;
    int res = solution.isPalindrome(x);
    cout << "input int : " << x << endl;
    cout << "solution  : " << res << endl;
}
