/*
小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，
小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。
输入描述:
输入为一个整数，即为圆半径的平方,范围在32位int范围内。


输出描述:
输出为一个整数，即为优雅的点的个数

输入例子:
25

输出例子:
12
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int reverseAdd(int a, int b)
{
    if (a > 70000 || a < 1 || b > 70000 || b < 1) {
        return -1;
    }
    string sa = to_string(a);
    string sb = to_string(b);
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    // cout << sa << endl;
    // cout << sb << endl;
    int ra = atoi(sa.c_str());
    int rb = atoi(sb.c_str());
    return ra + rb;
}

void formatTransform()
{
    // number(int, double,...) 2 string
    cout << to_string(43.120) << endl;

    std::ostringstream strs;
    strs << 45.130;
    std::string str = strs.str();
    cout << str << endl;

    int num = 123456;
    char ch[50];
    itoa(num, ch, 10);
    cout << ch << endl;


    cout << "---------------------" << endl;
    // string 2 int
    cout << atoi("14") << endl;
    cout << atoi("16.56") << endl;

    // string 2 double
    cout << stod("14.560") << endl;
    // long stol(string), float stof(string), double stod(string)
    // Defined in header <string>
    // int stoi(const std::string& str, std::size_t* pos = 0, int base = 10);
    // int stoi(const std::wstring& str, std::size_t* pos = 0, int base = 10); (1)	(since C++11)
    // long stol(const std::string& str, std::size_t* pos = 0, int base = 10);
    // long stol(const std::wstring& str, std::size_t* pos = 0, int base = 10); (2)	(since C++11)
    // long long stoll(const std::string& str, std::size_t* pos = 0, int base = 10);
    // long long stoll(const std::wstring& str, std::size_t* pos = 0, int base = 10); (3)	(since C++11)

    // string 2 const char*
    string ss = "123";
    const char* p = ss.c_str();

    // string 2 char*
    string s2 = "123";
    char* writable = new char[s2.size() + 1];
    std::copy(s2.begin(), s2.end(), writable);
    writable[s2.size()] = '\0';  // don't forget the terminating 0
    delete[] writable;           // don't forget to free the string after finished using it

    // char 2 string
    string s3;
    s3.assign("c-string");
    string s4("444");
}


bool isElegentNum(int num, int x)
{
    double y = sqrt(num - x * x);
    if ((y - int(y)) < 0.000001) {
        return true;
    }
    return false;
}

int elegentNum(int num)
{
    int cnt = 0;
    for (int i = 1; i < num; ++i) {
        if (isElegentNum(num, i)) {
            cnt++;
            cout << i << endl;
        }
    }
    cnt *= 4;
    return cnt;
}


int main()
{
    // formatTransform();
    // cout << reverseAdd(120, 450) << endl;

    int num = 25;
    cout << "total nums " << elegentNum(num) << endl;

    return 0;
}
