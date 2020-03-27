
#include <iostream>
using namespace std;

/**
 * @brief 求任一正整数的阶乘（注意：是任意正整数）
 *
 * **输入**\n
 * 输入一个正整数
 *
 * **输出**\n
 * 输出一个正整数
 *
 * 样例输入
 * ```
 * 3
 * 10
 * ```
 * 样例输出
 * ```
 * 6
 * 3628800
 * ```
 * @note
 * @see
 */
class XiaoMi2
{
public:
    unsigned long long res(unsigned long long n)
    {
        if (n == 1)
            return 1;
        return n * res(n - 1);
    }
};


int main()
{
    XiaoMi2 mi2;
    unsigned long long n;
    cin >> n;
    cout << mi2.res(n) << endl;
}
