#include <iostream>
using namespace std;

/**
 * @brief 路径规划（斐波拉契数列）
 *
 * **题目描述：**\n
 * 兔子从A地到B地，当中每1公里有一个休息站。
 * 兔子体力每次最多可连续行走2公里，也就是说兔子可以选择行走1公里或者2公里进行休息，然后继续前进。
 * 假设A地到B地距离N公里，求兔子的行走休息方案有多少种(每一种组合算一种)。
 * 备注：可不考虑整型溢出的问题，测试样例结果保证不超出2^31。
 *
 * **输入**\n
 * 输入一个整型，表示A地到B地的距离
 *
 * **输出**\n
 * 输出一个整型，表示行走方案数目
 *
 * **样例输入**\n
 * ```
 * 0
 * 1
 * 2
 * 5
 * ```
 * **样例输出**\n
 * ```
 * 1
 * 1
 * 2
 * 8
 * ```
 * @note
 * @see
 */
class XiaoMi3
{
public:
    unsigned long long recursive(int n)
    {
        if (n == 0)
            return 1;
        if (n <= 2)
            return n;
        return recursive(n - 1) + recursive(n - 2);
    }

    unsigned long long iterative(int n)
    {
        if (n == 0)
            return 1;
        if (n <= 2)
            return n;

        int f1 = 1, f2 = 2, f3;
        for (int i = 3; i <= n; ++i) {
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }

    unsigned long long m3(unsigned n)
    {
        // if (n == 0) return 1;
        // if (n <= 2) return n;

        double sum = 0, tmp1, tmp2;
        int i, j;

        for (i = 0; i <= n / 2; i++) {
            tmp1 = tmp2 = 1;
            for (j = 0; j < i; j++) {
                tmp1 *= (n - i - j);
                tmp2 *= (i - j);
            }
            sum += (tmp1 / tmp2);
        }

        return (unsigned long long)(sum);
    }

    void runTest()
    {
        int x = 100;
        for (int i = 0; i < x; i++) {
            cout << i;
            // cout << "  " << recursive(i);
            cout << "  " << iterative(i);
            // cout << "  " << m3(i);
            cout << endl;
        }
    }
};


int main()
{
    XiaoMi3 mi3;
    int n;
    cin >> n;
    cout << mi3.recursive(n) << endl;
    cout << mi3.iterative(n) << endl;
    return 0;
}
