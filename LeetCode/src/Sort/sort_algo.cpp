#include "sort_algo.h"
#include <time.h>  

CSortAlgo::CSortAlgo()
{
}

CSortAlgo::~CSortAlgo()
{
}


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
}

void CSortAlgo::print_nums(const vector<int> &nums)
{
	int len = nums.size();
	for (int i = 0; i < len; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

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

void CSortAlgo::merge(vector<int> &nums, vector<int> &nums_temp, int start_index, int mid_index, int end_index)
{
	/*int i = start_index, j = mid_index + 1;
	int k = 0;
	while (i < mid_index + 1 && j < end_index + 1)
	{
		if (nums[i] > nums[j])
			temp_arr[k++] = nums[j++];
		else
			temp_arr[k++] = nums[i++];
	}
	while (i < mid_index + 1)
	{
		temp_arr[k++] = nums[i++];
	}
	while (j < end_index + 1)
		temp_arr[k++] = nums[j++];

	for (i = 0, j = start_index; j < end_index + 1; i++, j++)
		nums[j] = temp_arr[i];*/
}

void CSortAlgo::merge_sort(vector<int> &nums)
{
	//if (start_index < end_index)
	//{
	//	int mid_index = (start_index + end_index) / 2;
	//	merge_sort(nums, temp_arr, start_index, mid_index);
	//	merge_sort(nums, temp_arr, mid_index + 1, end_index);
	//	merge(nums, temp_arr, start_index, mid_index, end_index);
	//}
}

void CSortAlgo::heap_sort(vector<int> &nums)
{

}

