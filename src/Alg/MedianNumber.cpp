#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief 寻找n个数的中位数
 *
 * Detailed explanation.
 * @note 
 * @see http://ilovers.sinaapp.com/article/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E5%92%8C%E5%AF%BB%E6%89%BE%E4%B8%AD%E4%BD%8D%E6%95%B0
 */
class AlgMedianNum
{
	/*! 
	 * @brief 基于快速排序的思路来找第k大的数。
	 *
	 * 划分和快速排序是一模一样的，递归那部分也很简单，
	 * 如果左半部分长就在左半部分找，如果右半部分长，就在右半部分找剩下的小一部分，
	 * 比如 nth == 10，如果左边个数是 4，那么就在右边找第 6th 大的数！跟快速排序不同的是，递归只需要针对一部分处理！

	 * @param data 数据
	 * @param start 起始位置
	 * @param last 最后一个数据的下一个位置
	 * @param nth 指定要寻找第 nth 大的数
	 * @return  要找的数
	 * @note  
	 * @see
	*/
	int select_middle(int *data, int start, int last, int nth)
	{
		int i = start + 1, j = last - 1, pivot = data[start];
		int k;
		if (last - start < 2)
			return data[start];

		while (i <= j)
		{
			if (data[i] < pivot) 
			{
				++i;
				continue;
			}
			if (data[j] >= pivot) 
			{
				--j;
				continue;
			}
			swap(data, i, j);
		}
		swap(data, i - 1, start);
		k = i - start;  // 左半部分的长度
		if (k == nth)  
			return data[i - 1];
		else if (k > nth)  
			return select_middle(data, start, i, nth);
		else 
			return select_middle(data, i, last, nth - k);
	}

	void quick_sort(int *data, int start, int last)
	{
		int i = start + 1, j = last - 1, pivot = data[start];
		if (last - start < 2)
			return;

		while (i <= j)
		{
			if (data[i] < pivot) 
			{
				++i;
				continue;
			}
			if (data[j] >= pivot)
			{
				--j;
				continue;
			}
			swap(data, i, j);
		}
		swap(data, i - 1, start);
		quick_sort(data, start, i);
		quick_sort(data, i, last);
	}

private:
	void swap(int *data, int i, int j)
	{
		int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}

public:
	void runTest()
	{
		int i, n = 9, middle;
		int data[] = { 1, 3, 7, 8, 3, 9, 15, 4, 6 };

		middle = select_middle(data, 0, n, (n + 1) / 2);
		quick_sort(data, 0, n);
		for (i = 0; i < n; i++)
			printf("%d ", data[i]);
		printf("\nmiddle number is %d\n", middle);
	}
};


#ifdef RUN_AlgMedianNum
int main()
{
	AlgMedianNum median;
	median.runTest();
	return 0;
}
#endif