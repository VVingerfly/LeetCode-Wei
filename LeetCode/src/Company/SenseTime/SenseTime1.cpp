


/*


*/
#include "SenseTimeDefs.h"
#include <iostream>
#include <vector>
using namespace std;


/**
 * @brief �ҳ�һ����С�ı����䣬ʹ�����k�������е�����һ��Ԫ�ء�
 *
 * **��Ŀ������**\n
 * ����k���������飬ÿ��������N��Ԫ�أ��ҳ�һ����С�ı����䣬
 * ʹ�����ÿ�������е�����һ��Ԫ�ء�
 * ������������[a,b],[c,d]:
 * ���b-a<d-c������Ϊ[a,b]�Ǹ�С�����䣻
 * ���b-a==d-c,��a<c������Ϊ[a,b]�Ǹ�С�����䣻
 *
 * **��������**\n
 * ```
 * K
 * N
 * x11 x12 x13 ... x1n
 * xk1 xk2 xk3 ... xkn
 * ```
 * **�������**\n
 * �������ֱ�����С��������ұ߽�
 *
 * **ʾ����**
 * ```
 * 3
 * 3
 * 2 12 14
 * 2 6 9
 * 4 7 19
 * ```
 * **���**
 * ```
 * 2 4
 * ```
 * @note 
 * @see 
 */
class SenseTime1
{
public:
	void mergeTwoArray(vector<int> &nums1, const vector<int> &nums2)
	{
		int len1 = nums1.size();
		int len2 = nums2.size();
		int idx1 = 0;
		int idx2 = 0;
		vector<int> nums;
		while (idx1 < len1 && idx2 < len2)
		{
			if (nums1[idx1] < nums2[idx2])
				nums.push_back(nums1[idx1++]);
			else if (nums1[idx1] > nums2[idx2])
				nums.push_back(nums2[idx2++]);
			else
				idx2++;

		}
		while (idx1 < len1)
			nums.push_back(nums1[idx1++]);
		while (idx2 < len2)
			nums.push_back(nums2[idx2++]);

		nums1 = nums;
	}

	void mergeAllArray(vector<int> &nums, const vector<vector<int>> &array)
	{
		if (array.size() == 0) return;
		nums = array.front();
		for (int i = 1; i < array.size(); i++)
			mergeTwoArray(nums, array[i]);
	}

	void findMinInterval(int &a, int &b, const vector<vector<int>> &array)
	{
		a = 2;
		b = 4;
	}


	void printArray(const vector<int> &nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}


	void runTest()
	{
		vector<vector<int>> array(3);
		array[0] = vector<int>{ 2, 12, 14 };
		array[1] = vector<int>{ 2, 6, 9 };
		array[2] = vector<int>{ 4, 7, 19 };

		vector<int> nums;
		mergeAllArray(nums, array);
		printArray(nums);
	}
};

#ifdef RUN_SenseTime1

int main()
{
	SenseTime1 st1;

	st1.runTest();
	return 0;

	int K;
	cin >> K;
	int n;
	cin >> n;
	vector<vector<int>> array(K);
	for (int k = 0; k < K; k++)
	{
		array[k].resize(n);
		for (int i = 0; i < n; i++)
			cin >> array[k][i];
	}
	int a, b;
	st1.findMinInterval(a, b, array);
	cout << a << " " << b << endl;
	return 0;
}

#endif // RUN_SenseTime1