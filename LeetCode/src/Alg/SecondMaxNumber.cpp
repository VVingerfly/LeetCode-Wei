#include "AlgDefs.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 找一个数组中第二大的数。
 *
 * @see
 - https://www.zhihu.com/question/22389585
*/
class AlgSecondMax
{
#define min(x,y) ((x<y)?x:y)
public:
	int GetUglyNumber(const vector<int> &data) 
	{
		int count = data.size();
		if (!count || count == 1)
			return -1;

		int maxVal = data[0] > data[1] ? data[0] : data[1];
		int smaxVal = data[0] + data[1] - maxVal;

		for (int i = 2; i < count; i++)
		{
			if (data[i] > maxVal)
			{
				smaxVal = maxVal;
				maxVal = data[i];
			}
			else if (data[i] < maxVal && data[i] > smaxVal)
				smaxVal = data[i];
		}

		return smaxVal;
	}

	void runTest()
	{
		vector<int> data{ 2, 4, 7, 12 };
		cout << GetUglyNumber(data) << endl;
	}

	
};


#ifdef RUN_AlgSecondMax
int main()
{

	AlgSecondMax res;
	res.runTest();

	return 0;
}
#endif
