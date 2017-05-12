/*
С����һ��Բ��������ԭ���Բ��С��֪��Բ�İ뾶��ƽ����С����Ϊ��Բ�ϵĵ���Һ������궼�������ĵ������ŵģ�
С��������Ѱ��һ���㷨��������ŵĵ�ĸ������������������
���磺�뾶��ƽ�����Ϊ25
���ŵĵ���У�(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)��һ��12���㡣
��������:
����Ϊһ����������ΪԲ�뾶��ƽ��,��Χ��32λint��Χ�ڡ�


�������:
���Ϊһ����������Ϊ���ŵĵ�ĸ���

��������:
25

�������:
12
*/
#pragma once


#include <iostream>
#include <vector>
#include <string> 
#include <sstream>

using namespace std;

int reverseAdd(int a, int b)
{
	if (a > 70000 || a < 1 || b > 70000 || b < 1)
	{
		return -1;
	}
	string sa = to_string(a);
	string sb = to_string(b);
	reverse(sa.begin(), sa.end());
	reverse(sb.begin(), sb.end());
	//cout << sa << endl;
	//cout << sb << endl;
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
	const char *p = ss.c_str();

	// string 2 char*
	string s2 = "123";
	char *writable = new char[s2.size() + 1];
	std::copy(s2.begin(), s2.end(), writable);
	writable[s2.size()] = '\0'; // don't forget the terminating 0	 
	delete[] writable;// don't forget to free the string after finished using it

	// char 2 string
	string s3;
	s3.assign("c-string");
	string s4("444");

}


bool isElegentNum(int num, int x)
{
	double y = sqrt(num - x*x);
	if ((y-int(y)) < 0.000001)
	{
		return true;
	}
	return false;
}

int elegentNum(int num)
{
	int cnt = 0;
	for (int i = 1; i < num; ++i)
	{
		if (isElegentNum(num, i))
		{
			cnt++;
			cout << i << endl;
		}
	}
	cnt *= 4;
	return cnt;
}


int main()
{
	//formatTransform();
	//cout << reverseAdd(120, 450) << endl;

	int num = 25;
	cout << "total nums " << elegentNum(num) << endl;

	return 0;
}


