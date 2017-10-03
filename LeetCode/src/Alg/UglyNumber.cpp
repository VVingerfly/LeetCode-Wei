/*! 
* \file F:\USTCStudy\CPlusPlus\LeetCode-Wei\LeetCode\src\Alg\UglyNumber.cpp
* \brief   
*    
*  
* \author Wei Li 
* \version 
* \date  2017/Sep/13 11:07:19
*/  

#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief ������ֻ��������2��3��5����,���մ�С�����˳��ĵ�N��������
 *
 * ��ֻ��������2��3��5������Ϊ����(Ugly Number)������6��8���ǳ�������14���ǣ���Ϊ����������7.
 * ϰ���ϣ����ǰ�1������һ�����������մ�С�����˳��ĵ�N��������
 * @see 
	- http://blog.csdn.net/coder_xia/article/details/6707600
	- http://www.iteye.com/topic/832545
 */
class AlgUglyNumber
{
#define min(x,y) ((x<y)?x:y)
public:
	void GetUglyNumber(int index)  //�ҵ���index������  
	{
		int i, time = 0;
		if (index < 1)
		{
			cout << "error input " << endl;
			exit(EXIT_FAILURE);
		}
		for (i = 1; i < INT_MAX && time < index; i++)
		{
			if (IsUglyNumber(i))
			{
				time++;
			}
		}
		cout << i - 1 << endl;
	}

	void FindUgly(int n) 
	{
		int* uglyNums = new int[n];
		uglyNums[0] = 1;
		int idx2 = 0;
		int idx3 = 0;
		int idx5 = 0;
		int idx = 1;
		while (idx < n)
		{
			int val = min(min(uglyNums[idx2] * 2, uglyNums[idx3] * 3), uglyNums[idx5] * 5); //����������һ������     
			if (val == uglyNums[idx2] * 2) //���������������index*���Ųһλ��    
				++idx2;
			if (val == uglyNums[idx3] * 3)   //���ﲻ����elseif����Ϊ������������Сֵ����ʱ��ҪŲ����  
				++idx3;
			if (val == uglyNums[idx5] * 5)
				++idx5;
			uglyNums[idx++] = val;
		}
		cout << uglyNums[n - 1] << endl;
		delete[] uglyNums;
	}

	void GetUglyNumberFast(int num)
	{
		int *uglyNums = new int[num];
		uglyNums[0] = 1;
		for (int count = 1, m2 = 0, m3 = 0, m5 = 0; count < num; count++) 
		{
			for (int i = 0; i < count; i++) 
			{
				if (uglyNums[i] * 2 > uglyNums[count - 1])
				{
					m2 = uglyNums[i] * 2;
					break;
				}
			}
			for (int i = 0; i < count; i++) 
			{
				if (uglyNums[i] * 3 > uglyNums[count - 1])
				{
					m3 = uglyNums[i] * 3;
					break;
				}
			}
			for (int i = 0; i < count; i++) 
			{
				if (uglyNums[i] * 5 > uglyNums[count - 1])
				{
					m5 = uglyNums[i] * 5;
					break;
				}
			}
			uglyNums[count] = min(m2, min(m3, m5));
		}
		cout << uglyNums[num - 1] << endl;
	}


private:
	int IsUglyNumber(int num)
	{
		while (num % 2 == 0)
		{
			num /= 2;
		}
		while (num % 3 == 0)
		{
			num /= 3;
		}
		while (num % 5 == 0)
		{
			num /= 5;
		}
		if (num == 1)
			return 1;
		else
			return 0;  //not an ugly number  
	}
};


#ifdef RUN_AlgUglyNumber
int main()
{

	AlgUglyNumber res;
	res.GetUglyNumberFast(6);
	res.FindUgly(6);
	//res.GetUglyNumber(1500);
	

	return 0;
}
#endif

