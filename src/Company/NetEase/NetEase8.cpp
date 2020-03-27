/*
A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
输入描述:
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。
范围均在-30到30之间(闭区间)。


输出描述:
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。
如果不存在这样的整数A，B，C，则输出No

输入例子:
1 -2 3 4

输出例子:
2 1 3
*/


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int candyNum(int a, int b, int c, int d, int* res)
{
    int A2 = a + c;
    if (A2 % 2 != 0) {
        return -1;
    }
    res[0] = A2 / 2;
    int B2 = b + d;
    if (B2 % 2 != 0) {
        return -1;
    }

    res[1] = B2 / 2;
    res[2] = d - res[1];
    if (res[0] - res[1] != a || res[1] - res[2] != b || res[0] + res[1] != c || res[1] + res[2] != d) {
        return -1;
    }
    return 1;
}


int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res[3] = { 0, 0, 0 };
    if (candyNum(a, b, c, d, res) == 1) {
        cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
