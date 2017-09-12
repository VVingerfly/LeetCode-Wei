#include "sort_algo.h"
#include <time.h>  

CSortAlgo::CSortAlgo()
{
}

CSortAlgo::~CSortAlgo()
{
}

/*! @brief �����㷨���Ժ���
*/
void CSortAlgo::test_sort()
{
	vector<int> nums_sort = nums_;

	cout << "input  nums: ";
	print_nums(nums_sort);

	bubble_sort(nums_sort);
	cout << "bubble sort: ";
	print_nums(nums_sort);

	nums_sort = nums_;
	select_sort(nums_sort);
	cout << "select sort: ";
	print_nums(nums_sort);

	nums_sort = nums_;
	insert_sort(nums_sort);
	cout << "insert sort: ";
	print_nums(nums_sort);

	nums_sort = nums_;
	quick_sort(nums_sort, 0, nums_sort.size()-1);
	cout << "quick  sort: ";
	print_nums(nums_sort);

	nums_sort = nums_;
	vector<int> nums_temp(nums_sort.size());
	merge_sort(nums_sort, nums_temp, 0, nums_sort.size() - 1);
	cout << "merge  sort: ";
	print_nums(nums_sort);

	nums_sort = nums_;
	heap_sort(nums_sort);
	cout << "heap   sort: ";
	print_nums(nums_sort);
}

/*! @brief print all the elements of a array
* @param nums the array to print
*/
void CSortAlgo::print_nums(const vector<int> &nums)
{
	int len = nums.size();
	for (int i = 0; i < len; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

/*! generate a int array with size len
* @param len the length of the array
*/
void CSortAlgo::randon_nums(int len)
{
	int a = -len;
	int b = len;
	nums_.clear();
	srand((unsigned)time(NULL));
	for (int i = 0; i < len; i++)
	{
		nums_.push_back((rand() % (b - a + 1)) + a);  //[a, b]
	}
}


/*! @brief ð������
*
* �㷨֮ԭ�� ���ڵ����ݽ��������Ƚϣ�С������ǰ�棬�������ں���, 
*			  ����һ����������С�����ͱ������˵�һλ���ڶ���Ҳ����ˣ�������ƣ�ֱ�����е�����������ɡ� \n
* ʱ�临�Ӷȣ� ƽ�� O(n^2) � O(n^2) \n
* �ռ临�Ӷȣ� O(1) \n
* �㷨�ȶ��ԣ� �ȶ� \n
* @param nums the array to sort
*/
void CSortAlgo::bubble_sort(vector<int> &nums)
{
	int len = nums.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (nums[j] < nums[j - 1])
			{
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
	}
}


/*! @brief ѡ������

* �㷨֮ԭ�� ����δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�
*			  Ȼ���ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�
*			  Ȼ��ŵ����������е�ĩβ���Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�\n
* ʱ�临�Ӷȣ� ƽ�� O(n^2) � O(n^2) \n
* �ռ临�Ӷȣ� O(1) \n
* �㷨�ȶ��ԣ� ���ȶ� \n
* @param nums the array to sort
*/
void CSortAlgo::select_sort(vector<int> &nums)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		int index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (nums[j] < nums[index])
				index = j;
		}
		if (index != i)
		{
			int temp = nums[i];
			nums[i] = nums[index];
			nums[index] = temp;
		}
	}
}


/*! @brief ��������

 * �㷨֮ԭ�� �����ݷ�Ϊ�����֣����򲿷������򲿷֣�һ��ʼ���򲿷ְ�����1��Ԫ�أ�
 *			   ���ν������Ԫ�ز��뵽���򲿷֣�ֱ������Ԫ������
 *			   ���������ַ�Ϊֱ�Ӳ������򡢶��ֲ��������������ȣ�����ֻ����ֱ�Ӳ�������\n
 * ʱ�临�Ӷȣ� ƽ�� O(n^2) � O(n^2) \n
 * �ռ临�Ӷȣ� O(1) \n
 * �㷨�ȶ��ԣ� �ȶ� \n
 * @param nums the array to sort
*/
void CSortAlgo::insert_sort(vector<int> &nums)
{
	int len = nums.size();
	for (int i = 1; i < len; i++)
	{
		int j = i - 1;
		int k = nums[i];
		while (j > -1 && k < nums[j])
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = k;
	}
}


/*! @brief ��������
 * @details
 * �㷨֮ԭ�� ����������Ŀǰ��ʵ���зǳ���Ч��һ�������㷨��
 *			   ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��
 *			   Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�\n
 * ʱ�临�Ӷȣ� ƽ�� O(nlogn) � O(n^2) \n
 * �ռ临�Ӷȣ� O(logn) \n
 * �㷨�ȶ��ԣ� ���ȶ� \n
 * @param nums the array to sort
 * @param left 
 * @param right 
*/
void CSortAlgo::quick_sort(vector<int> &nums, int left, int right)
{
	int len = nums.size();
	if (left < right)
	{
		int i = left, j = right, target = nums[left];
		while (i < j)
		{
			while (i < j && nums[j] > target)
				j--;
			if (i < j)
				nums[i++] = nums[j];

			while (i < j && nums[i] < target)
				i++;
			if (i < j)
				nums[j] = nums[i];
		}
		nums[i] = target;
		quick_sort(nums, left, i - 1);
		quick_sort(nums, i + 1, right);
	}
}

/*! @brief �鲢����

 * �㷨֮ԭ�� �鲢������幤��ԭ�����£��������й���n��Ԫ�أ���
 * ������ÿ�����������ֽ��й鲢������merge)���γ�floor(n / 2)�����У������ÿ�����а�������Ԫ��
 * �����������ٴι鲢���γ�floor(n / 4)�����У�ÿ�����а����ĸ�Ԫ��
 * �ظ�����2��ֱ������Ԫ��������ϡ�\n
 * ʱ�临�Ӷȣ� ƽ�� O(nlogn) � O(nlogn) \n
 * �ռ临�Ӷȣ� O(1) \n
 * �㷨�ȶ��ԣ� �ȶ� \n
 * @param nums the array to sort
 * @note �����ʹ�������ʵ�ֵĻ����ռ临�Ӷȿ��ԴﵽO(1)��
 * �������ʹ���������洢���ݵĻ����ڹ鲢�Ĺ����У���Ҫ��ʱ�ռ����洢�鲢�õ����ݣ����Կռ临�Ӷ�ΪO(n)
*/
void CSortAlgo::merge_sort(vector<int> &nums, vector<int> &nums_temp, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int mid_index = (start_index + end_index) / 2;
		merge_sort(nums, nums_temp, start_index, mid_index);
		merge_sort(nums, nums_temp, mid_index + 1, end_index);
		merge(nums, nums_temp, start_index, mid_index, end_index);
	}
}

void CSortAlgo::merge(vector<int> &nums, vector<int> &nums_temp, int start_index, int mid_index, int end_index)
{
	// ���ж�����������nums[start_index...mid_index]��nums[mid_index...end_index]�ϲ���  
	int i = start_index, j = mid_index + 1;
	int k = 0;
	while (i < mid_index + 1 && j < end_index + 1)
	{
		if (nums[i] > nums[j])
			nums_temp[k++] = nums[j++];
		else
			nums_temp[k++] = nums[i++];
	}
	while (i < mid_index + 1)
		nums_temp[k++] = nums[i++];
	while (j < end_index + 1)
		nums_temp[k++] = nums[j++];

	for (i = 0, j = start_index; j < end_index + 1; i++, j++)
		nums[j] = nums_temp[i];
}

/*! @brief ������

* �㷨֮ԭ�� ��������Ϊ����
*			1. �Ƚ���ʼ����R[1..n]����һ�����ѣ��˶�Ϊ��ʼ��������
*			2. �ٽ��ؼ������ļ�¼R[1]�����Ѷ����������������һ����¼R[n]������
*			�ɴ˵õ��µ�������R[1..n - 1]��������R[n]��������R[1..n - 1].keys��R[n].key
*			3. ���ڽ������µĸ�R[1]����Υ�������ʣ���Ӧ����ǰ������R[1..n - 1]����Ϊ�ѡ�
*			�ظ�2��3���裬ֱ��������ֻ��һ��Ԫ��Ϊֹ��\n
* ʱ�临�Ӷȣ� ƽ�� O(nlogn) � O(nlogn) \n
* �ռ临�Ӷȣ� O(1) \n
* �㷨�ȶ��ԣ� ���ȶ� \n
* @param nums the array to sort
*/
void CSortAlgo::heap_sort(vector<int> &nums)
{
	int len = nums.size();
	int i;
	// �������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		heap_adjust(nums, i, len);
	}

	for (i = len - 1; i > 0; i--)
	{
		// ����1��Ԫ���뵱ǰ���һ��Ԫ�ؽ�������֤��ǰ�����һ��λ�õ�Ԫ�ض������ڵ��������������
		int temp = nums[0];
		nums[0] = nums[i];
		nums[i] = temp;
		// ������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
		heap_adjust(nums, 0, i);
	}
}

/*��
 * ������arr���������
 * @param nums ������������
 * @param i    ������������Ԫ�ص��±�
 * @param len  ����ĳ���
 */
void CSortAlgo::heap_adjust(vector<int> &nums, int i, int len)
{
	int child;
	int temp;
	for (; 2 * i + 1 < len; i = child)
	{
		child = 2 * i + 1;  // �ӽ���λ�� = 2 * ������λ�� + 1
							// �õ��ӽ���м�ֵ�ϴ�Ľ��
		if (child < len - 1 && nums[child + 1] > nums[child])
			child++;
		// ����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
		if (nums[i] < nums[child])
		{
			temp = nums[i];
			nums[i] = nums[child];
			nums[child] = temp;
		}
		else
			break;
	}
}

