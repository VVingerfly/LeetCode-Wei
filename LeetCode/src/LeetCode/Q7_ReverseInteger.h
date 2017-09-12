//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Apr/3 17:00:55
// Last Change  : 2017/Apr/3 17:00:58
// Summary      :
//===============================================================

/****************************************************************
Description:
	Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
	The input is assumed to be a 32-bit signed integer.
	Your function should return 0 when the reversed integer overflows.

Difficulty : Easy
******************************************************************/

#include <iostream>
#include <string>
using namespace std;

#ifndef Q7_ReverseInteger_h__
#define Q7_ReverseInteger_h__
class A7_ReverseInteger
{
public:
	int reverse(int x) 
	{
		//cout << INT_MAX << endl;
		//cout << INT_MIN << endl;
		bool is_positive = x >= 0 ? true : false;
		string s_max = to_string(INT_MAX);
		string s_min = to_string(INT_MIN);
		s_min = s_min.substr(1, s_min.length() - 1);
		cout << "s_max = " << s_max << endl;
		cout << "s_min = " << s_min << endl;
		string x_str = to_string(x);
		cout << "x_str = " << x_str << endl;
		if (x < 0)
		{
			x_str = x_str.substr(1, x_str.length());
		}
		
		cout << "x_str = " << x_str << endl;
		string x_str_inv(x_str.rbegin(), x_str.rend());
		cout << "x_str reverse = " << x_str_inv << endl;
		if (x_str_inv.length() == s_max.length())
		{
			if (is_positive && x_str_inv > s_max)
			{
				return 0;
			}
			if (!is_positive && x_str_inv > s_min)
			{
				return 0;
			}
		}

		return is_positive ? atoi(x_str_inv.c_str()) : -atoi(x_str_inv.c_str());
	}
};


void TestQ7()
{
	int num1 = 123;
	int num2 = -123;
	int num3 = -2147483648;
	int num = num3;
	A7_ReverseInteger solution;
	int res = solution.reverse(num);
	cout << "input number : " << num << endl;
	cout << "solution     : " << res << endl;
}


#endif // Q7_ReverseInteger_h__











