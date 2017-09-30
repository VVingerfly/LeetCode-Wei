



#include "NetEaseDefs.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief 纠正时钟的显示时间。
 *
 * Detailed explanation.
 * @note 
 * @see 
 */
class CNetEase11
{
public:
	/**
	@brief 纠正时钟的显示时间。

	小W有一个电子时钟用于显示时间，显示的格式为HH:MM:SS，HH，MM，SS分别表示时，分，秒。
	其中时的范围为[‘00’,‘01’…‘23’]，分的范围为[‘00’,‘01’…‘59’]，秒的范围为[‘00’,‘01’…‘59’]。
	但是有一天小W发现钟表似乎坏了，显示了一个不可能存在的时间“98:23:00”，
	小W希望改变最少的数字，使得电子时钟显示的时间为一个真实存在的时间，
	譬如“98:23:00”通过修改第一个’9’为’1’，即可成为一个真实存在的时间“18:23:00”。
	修改的方法可能有很多，小W想知道，在满足改变最少的数字的前提下，符合条件的字典序最小的时间是多少。
	其中字典序比较为用“HHMMSS”的6位字符串进行比较。

	输入描述:
	每个输入数据包含多个测试点。
	每个测试点后有一个空行。
	第一行为测试点的个数T(T<=100)。
	每个测试点包含1行，为一个字符串”HH:MM:SS”，表示钟表显示的时间。

	输出描述:
	对于每个测试点，输出一行。
	如果钟表显示的时间为真实存在的时间，则不做改动输出该时间，
	否则输出一个新的”HH:MM:SS”，表示修改最少的数字情况下，字典序最小的真实存在的时间。

	输入
	```
	2
	19:90:23
	23:59:59
	```
	输出
	```
	19:00:23
	23:59:59
	```
	*/
	string correctTime(string &tStr)
	{
		correctHour(tStr);
		correctMinSnd(tStr);
		return tStr;
	}
	void correctHour(string &tStr)
	{
		if (tStr.at(0) < '0' || tStr.at(0) > '2')
			tStr.at(0) = '0';

		if (tStr.at(1) < '0' || tStr.at(1) > '9')
			tStr.at(1) = '0';
		else if (tStr.at(1) > '3' && tStr.at(0) == '2')
		{
			tStr.at(0) = '0';
		}
	}

	void correctMinSnd(string &tStr)
	{
		int i = 3;
		if (tStr.at(i) < '0' || tStr.at(i) > '5')
			tStr.at(i) = '0';
		i = 4;
		if (tStr.at(i) < '0' || tStr.at(i) > '9')
			tStr.at(i) = '0';
		i = 6;
		if (tStr.at(i) < '0' || tStr.at(i) > '5')
			tStr.at(i) = '0';
		i = 7;
		if (tStr.at(i) < '0' || tStr.at(i) > '9')
			tStr.at(i) = '0';
	}

	void runTest()
	{
		vector<string> strVec;
		strVec.push_back("19:90:23");
		strVec.push_back("23:59:59");
		strVec.push_back("29:59:59");

		for (int i = 0; i < strVec.size(); i++)
		{
			cout << correctTime(strVec[i]) << endl;
		}
	}
};


#ifdef RUN_NetEase11
int main()
{
	CNetEase11 obj;
#if 1
	obj.runTest();
#else
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tStr;
		cin >> tStr;
		cout << obj.correctTime(tStr) << endl;
	}

#endif
	return 0;
}
#endif


