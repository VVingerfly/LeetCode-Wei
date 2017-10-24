#include "AlgDefs.h"
#include <iostream>
using namespace std;

/**
 * @brief Ѱ��n��������λ��
 *
 * Detailed explanation.
 * @note 
 * @see http://ilovers.sinaapp.com/article/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E5%92%8C%E5%AF%BB%E6%89%BE%E4%B8%AD%E4%BD%8D%E6%95%B0
 */
class AlgMedianNum
{
	/*! 
	 * @brief ���ڿ��������˼·���ҵ�k�������
	 *
	 * ���ֺͿ���������һģһ���ģ��ݹ��ǲ���Ҳ�ܼ򵥣�
	 * �����벿�ֳ�������벿���ң�����Ұ벿�ֳ��������Ұ벿����ʣ�µ�Сһ���֣�
	 * ���� nth == 10�������߸����� 4����ô�����ұ��ҵ� 6th �����������������ͬ���ǣ��ݹ�ֻ��Ҫ���һ���ִ���

	 * @param data ����
	 * @param start ��ʼλ��
	 * @param last ���һ�����ݵ���һ��λ��
	 * @param nth ָ��ҪѰ�ҵ� nth �����
	 * @return  Ҫ�ҵ���
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
		k = i - start;  // ��벿�ֵĳ���
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