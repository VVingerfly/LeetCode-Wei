#include <iostream>
#include <random>
#include <vector>
using namespace std;

/**
 * @brief 拟合二维平面中的带噪音直线.
 *
 * **题目描述：**\n
 * 拟合二维平面中的带噪音直线，其中有不超过10%的样本点远离了直线，
 * 另外90%的样本点可能有高斯噪声的偏移，要求输出为ax+by+c=0的形式，其中a>0,a^2+b^2=1

 * **输入**\n
 * 第一个数n表示样本点个数
 * 其后2n个数表示每个点的xy

 * **输出**\n
 * abc,至多可以到6位有效数字。

 * **示例**
 * ```
 * 5
 * 3 4
 * 6 8
 * 9 12
 * 15 20
 * 10 -10
 * ```
 * **输出**
 * ```
 * -0.80000 0.600000 0.000000
 * ```
 * @note
 * @see
 */
class SenseTime2
{
public:
    struct Point
    {
        float x;
        float y;
    };
    void ransacLineFit(const vector<Point>& pts, int iter = 100, float eps = 0.1)
    {
        int n = pts.size();
        float bestk, bestb;
        int bestFitCnt = 0;
        for (int i = 0; i < iter; i++) {
            int idx1 = (rand() % n);  // 随机选择两个点
            int idx2 = (rand() % n);
            Point p1 = pts[idx1];
            Point p2 = pts[idx2];

            if (abs(p1.x - p2.x) < 0.00001)
                continue;

            float k = (p1.y - p2.y) / (p1.x - p2.x);  // y = kx+b
            float b = p1.y - k * p1.x;

            int fitCnt = 0;
            float len = sqrt(k * k + 1);
            for (int pi = 0; pi < pts.size(); ++pi) {
                Point p = pts.at(pi);
                float d = abs(k * p.x - p.y + b) / len;
                if (d < eps)
                    fitCnt++;
            }
            if (fitCnt > bestFitCnt) {
                bestFitCnt = fitCnt;
                bestk = k;
                bestb = b;
            }
        }

        float s = sqrt(bestk * bestk + 1);
        float a = bestk / s;
        float b = -1.0 / s;
        float c = bestb / s;
        if (bestk < 0)
            cout << -a << " " << -b << " " << -c << endl;
        else
            cout << a << " " << b << " " << c << endl;
    }

    void runTest()
    {
        vector<Point> pts(5);
        pts[0].x = 3;
        pts[0].y = 4;
        pts[1].x = 6;
        pts[1].y = 8;
        pts[2].x = 9;
        pts[2].y = 12;
        pts[3].x = 15;
        pts[3].y = 20;
        pts[4].x = 10;
        pts[4].y = -10;

        ransacLineFit(pts, 100, 0.0001);
    }

    void runTest2()
    {
        int n;
        cin >> n;
        vector<Point> pts(n);
        for (int i = 0; i < n; i++)
            cin >> pts[i].x >> pts[i].y;

        ransacLineFit(pts, 100, 0.0001);
    }
};


int main()
{
    SenseTime2 st2;
    st2.runTest();

    return 0;
}
