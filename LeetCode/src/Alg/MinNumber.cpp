#include "AlgDefs.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& str1, const string &str2)
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;
	return s1 < s2;
}

/**
 * @brief �������ų���С������
 *
 * ˼·���Ƚ���������תΪ�ַ������飬Ȼ���ַ�������������������������ַ������鼴�ɡ�
 * ����ע������ַ����ıȽϺ�����Ҫ���¶��壬���ǱȽ�a��b�����ǱȽ�ab�� ba��
 * - ���ab < ba����a < b��
 * - ���ab > ba����a > b��
 * - ���ab = ba����a = b��
 
 * �ȽϺ����Ķ����Ǳ���������Ĺؼ����������ʵ����ϣ���������ҵ�һ��������򣬸�����������ų������������ų�һ����С�����֡�
 * @see
 - http://www.cnblogs.com/youxin/p/3294154.html
*/
class AlgMinNum
{
#define min(x,y) ((x<y)?x:y)
public:


	void ComArrayMin(const vector<int> &pArray)
	{
		int num = pArray.size();
		int i;
		string *pStrArray = new string[num];

		for (i = 0; i < num; i++)
		{
			pStrArray[i] = to_string(pArray[i]);
		}

		sort(pStrArray, pStrArray + num, compare);

		for (i = 0; i < num; i++)
			cout << pStrArray[i];
		cout << endl;
		delete[] pStrArray;

	}

	void runTest()
	{
		vector<int> pArray{ 321, 32 };
		ComArrayMin(pArray);
	}
	
};


#ifdef RUN_AlgMinNum
int main()
{

	AlgMinNum res;
	res.runTest();

	return 0;
}
#endif
