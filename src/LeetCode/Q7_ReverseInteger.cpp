/**
 * @file Q7_ReverseInteger.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 整数反转
 * @version 0.1
 * @date 2017-04-03
 *
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * @brief 整数反转
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 示例 1:
 * - 输入: 123
 * - 输出: 321
 *
 * 示例 2:
 * - 输入: -123
 * - 输出: -321
 *
 * 示例 3:
 * - 输入: 120
 * - 输出: 21
 *
 * 注意:
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 *
 * @note https://leetcode-cn.com/problems/reverse-integer
 *
 */
class A7_ReverseInteger
{
public:
    int reverse(int x)
    {
        // -1234  ->  4321
        const int maxi_10 = INT_MAX / 10;    // INT_MAX = 2147483647
        const int mini_10 = INT_MIN / 10;    // INT_MIN = -2147483648
        int ans = 0;
        int pop = 0;
        while (x != 0) {
            pop = x % 10;
            // ans = ans * 10 + pop; // wrong
            // std::cout << x << " " << pop << " " << ans <<endl;
            if (ans > maxi_10 || (ans == maxi_10 && pop > 7)) 
                return 0;
            if (ans < mini_10 || (ans == mini_10 && pop < -8))
                return 0;
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
    int reverse_(int x)
    {
        bool is_positive = x >= 0 ? true : false;
        string s_max = to_string(INT_MAX);
        string s_min = to_string(INT_MIN);
        s_min = s_min.substr(1, s_min.length() - 1);

        string x_str = to_string(x);
        cout << "x_str = " << x_str << endl;
        if (x < 0) {
            x_str = x_str.substr(1, x_str.length());
        }
        cout << "x_str = " << x_str << endl;
        string x_str_inv(x_str.rbegin(), x_str.rend());
        cout << "x_str reverse = " << x_str_inv << endl;
        if (x_str_inv.length() == s_max.length()) {
            if (is_positive && x_str_inv > s_max) {
                return 0;
            }
            if (!is_positive && x_str_inv > s_min) {
                return 0;
            }
        }

        return is_positive ? atoi(x_str_inv.c_str()) : -atoi(x_str_inv.c_str());
    }
};

int main()
{
    vector<int> nums = { 123, -123, -3648, 120, INT_MAX, INT_MIN, -2147483412};
    vector<int> rlts = { 321, -321, -8463, 21, 0, 0, -2143847412};
    for (int i = 0; i < nums.size(); ++i) {
        A7_ReverseInteger solution;
        int res = solution.reverse(nums[i]);
        cout << ((res == rlts[i]) ? "Pass" : "Failed") << endl;
        cout << "  input  : " << nums[i] << endl;
        cout << "  result : " << res << endl;
        cout << "  answer : " << rlts[i] << endl;
    }

    return 0;
}
