



#include "NetEaseDefs.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief ����ʱ�ӵ���ʾʱ�䡣
 *
 * Detailed explanation.
 * @note 
 * @see 
 */
class CNetEase11
{
public:
	/**
	@brief ����ʱ�ӵ���ʾʱ�䡣

	СW��һ������ʱ��������ʾʱ�䣬��ʾ�ĸ�ʽΪHH:MM:SS��HH��MM��SS�ֱ��ʾʱ���֣��롣
	����ʱ�ķ�ΧΪ[��00��,��01������23��]���ֵķ�ΧΪ[��00��,��01������59��]����ķ�ΧΪ[��00��,��01������59��]��
	������һ��СW�����ӱ��ƺ����ˣ���ʾ��һ�������ܴ��ڵ�ʱ�䡰98:23:00����
	СWϣ���ı����ٵ����֣�ʹ�õ���ʱ����ʾ��ʱ��Ϊһ����ʵ���ڵ�ʱ�䣬
	Ʃ�硰98:23:00��ͨ���޸ĵ�һ����9��Ϊ��1�������ɳ�Ϊһ����ʵ���ڵ�ʱ�䡰18:23:00����
	�޸ĵķ��������кܶ࣬СW��֪����������ı����ٵ����ֵ�ǰ���£������������ֵ�����С��ʱ���Ƕ��١�
	�����ֵ���Ƚ�Ϊ�á�HHMMSS����6λ�ַ������бȽϡ�

	��������:
	ÿ���������ݰ���������Ե㡣
	ÿ�����Ե����һ�����С�
	��һ��Ϊ���Ե�ĸ���T(T<=100)��
	ÿ�����Ե����1�У�Ϊһ���ַ�����HH:MM:SS������ʾ�ӱ���ʾ��ʱ�䡣

	�������:
	����ÿ�����Ե㣬���һ�С�
	����ӱ���ʾ��ʱ��Ϊ��ʵ���ڵ�ʱ�䣬�����Ķ������ʱ�䣬
	�������һ���µġ�HH:MM:SS������ʾ�޸����ٵ���������£��ֵ�����С����ʵ���ڵ�ʱ�䡣

	����
	```
	2
	19:90:23
	23:59:59
	```
	���
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


