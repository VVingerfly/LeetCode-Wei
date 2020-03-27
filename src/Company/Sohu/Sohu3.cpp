#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Use brief, otherwise the index won't have a brief explanation.
 *
 * Detailed explanation.
 * @note
 * @see
 */
class CSohu3
{
public:
    /*!
     * @brief 用二分法计算sqrt(n)的值
     * @param n
     * @return the value of sqrt(n)
     * @note
     */
    double evalSqrtNBisection(int n)
    {
        long long i = 0;
        long long j = n / 2 + 1;
        while (i <= j) {
            long long mid = (i + j) / 2;
            long long sq = mid * mid;
            if (sq == n)
                return mid;
            else if (sq < n)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return j;
    }

    /*!
    * @brief 用牛顿法计算sqrt(n)

    * 求f(x) = x*x - n的零点, 倒数为f'(x) = 2*x \n
    * 迭代公式x(i+1) = x(i) - f(x(i)) / f'(x(i))
    * @param n
    * @return sqrt(n)
    * @note
    * @see http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
    */
    double evalSqrtNNewton(int n)
    {
        if (n == 0)
            return 0;
        double last = 0.0;
        double res = 1.0;
        while (res != last) {
            last = res;
            res = (res + n / res) / 2;
        }
        return res;
    }

    void runTest()
    {
        int n = 3;
        cout << "sqrt(" << n << ") = " << endl;
        cout << "bisection method " << evalSqrtNBisection(n) << endl;
        cout << "newton    method " << evalSqrtNNewton(n) << endl;
    }
};


int main()
{
    CSohu3 res;
    res.runTest();
    return 0;
}
