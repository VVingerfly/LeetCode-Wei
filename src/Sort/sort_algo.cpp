#include "sort_algo.h"
#include <time.h>

CSortAlgo::CSortAlgo() {}

CSortAlgo::~CSortAlgo() {}

/*! @brief 排序算法测试函数
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
    quick_sort(nums_sort, 0, nums_sort.size() - 1);
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
void CSortAlgo::print_nums(const vector<int>& nums)
{
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
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
    for (int i = 0; i < len; i++) {
        nums_.push_back((rand() % (b - a + 1)) + a);  //[a, b]
    }
}


/*! @brief 冒泡排序
 *
 * 算法之原理： 相邻的数据进行两两比较，小数放在前面，大数放在后面,
 *			  这样一趟下来，最小的数就被排在了第一位，第二趟也是如此，如此类推，直到所有的数据排序完成。 \n
 * 时间复杂度： 平均 O(n^2) 最坏 O(n^2) \n
 * 空间复杂度： O(1) \n
 * 算法稳定性： 稳定 \n
 * @param nums the array to sort
 */
void CSortAlgo::bubble_sort(vector<int>& nums)
{
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
}


/*! @brief 选择排序

* 算法之原理： 先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
*			  然后，再从剩余未排序元素中继续寻找最小（大）元素，
*			  然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。\n
* 时间复杂度： 平均 O(n^2) 最坏 O(n^2) \n
* 空间复杂度： O(1) \n
* 算法稳定性： 不稳定 \n
* @param nums the array to sort
*/
void CSortAlgo::select_sort(vector<int>& nums)
{
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int index = i;
        for (int j = i + 1; j < len; j++) {
            if (nums[j] < nums[index])
                index = j;
        }
        if (index != i) {
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
        }
    }
}


/*! @brief 插入排序

 * 算法之原理： 将数据分为两部分，有序部分与无序部分，一开始有序部分包含第1个元素，
 *			   依次将无序的元素插入到有序部分，直到所有元素有序。
 *			   插入排序又分为直接插入排序、二分插入排序、链表插入等，这里只讨论直接插入排序。\n
 * 时间复杂度： 平均 O(n^2) 最坏 O(n^2) \n
 * 空间复杂度： O(1) \n
 * 算法稳定性： 稳定 \n
 * @param nums the array to sort
*/
void CSortAlgo::insert_sort(vector<int>& nums)
{
    int len = nums.size();
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        int k = nums[i];
        while (j > -1 && k < nums[j]) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = k;
    }
}


/*! @brief 快速排序
 * @details
 * 算法之原理： 快速排序是目前在实践中非常高效的一种排序算法。
 *			   通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
 *			   然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。\n
 * 时间复杂度： 平均 O(nlogn) 最坏 O(n^2) \n
 * 空间复杂度： O(logn) \n
 * 算法稳定性： 不稳定 \n
 * @param nums the array to sort
 * @param left
 * @param right
 */
void CSortAlgo::quick_sort(vector<int>& nums, int left, int right)
{
    int len = nums.size();
    if (left < right) {
        int i = left, j = right, target = nums[left];
        while (i < j) {
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

/*! @brief 归并排序

 * 算法之原理： 归并排序具体工作原理如下（假设序列共有n个元素）：
 * 将序列每相邻两个数字进行归并操作（merge)，形成floor(n / 2)个序列，排序后每个序列包含两个元素
 * 将上述序列再次归并，形成floor(n / 4)个序列，每个序列包含四个元素
 * 重复步骤2，直到所有元素排序完毕。\n
 * 时间复杂度： 平均 O(nlogn) 最坏 O(nlogn) \n
 * 空间复杂度： O(1) \n
 * 算法稳定性： 稳定 \n
 * @param nums the array to sort
 * @note 如果是使用链表的实现的话，空间复杂度可以达到O(1)，
 * 但如果是使用数组来存储数据的话，在归并的过程中，需要临时空间来存储归并好的数据，所以空间复杂度为O(n)
*/
void CSortAlgo::merge_sort(vector<int>& nums, vector<int>& nums_temp, int start_index, int end_index)
{
    if (start_index < end_index) {
        int mid_index = (start_index + end_index) / 2;
        merge_sort(nums, nums_temp, start_index, mid_index);
        merge_sort(nums, nums_temp, mid_index + 1, end_index);
        merge(nums, nums_temp, start_index, mid_index, end_index);
    }
}

void CSortAlgo::merge(vector<int>& nums, vector<int>& nums_temp, int start_index, int mid_index, int end_index)
{
    // 将有二个有序数列nums[start_index...mid_index]和nums[mid_index...end_index]合并。
    int i = start_index, j = mid_index + 1;
    int k = 0;
    while (i < mid_index + 1 && j < end_index + 1) {
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

/*! @brief 堆排序

* 算法之原理： （以最大堆为例）
*			1. 先将初始数据R[1..n]建成一个最大堆，此堆为初始的无序区
*			2. 再将关键字最大的记录R[1]（即堆顶）和无序区的最后一个记录R[n]交换，
*			由此得到新的无序区R[1..n - 1]和有序区R[n]，且满足R[1..n - 1].keys≤R[n].key
*			3. 由于交换后新的根R[1]可能违反堆性质，故应将当前无序区R[1..n - 1]调整为堆。
*			重复2、3步骤，直到无序区只有一个元素为止。\n
* 时间复杂度： 平均 O(nlogn) 最坏 O(nlogn) \n
* 空间复杂度： O(1) \n
* 算法稳定性： 不稳定 \n
* @param nums the array to sort
*/
void CSortAlgo::heap_sort(vector<int>& nums)
{
    int len = nums.size();
    int i;
    // 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    for (int i = len / 2 - 1; i >= 0; i--) {
        heap_adjust(nums, i, len);
    }

    for (i = len - 1; i > 0; i--) {
        // 将第1个元素与当前最后一个元素交换，保证当前的最后一个位置的元素都是现在的这个序列中最大的
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        // 不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        heap_adjust(nums, 0, i);
    }
}

/*！
 * 将数组arr构建大根堆
 * @param nums 待调整的数组
 * @param i    待调整的数组元素的下标
 * @param len  数组的长度
 */
void CSortAlgo::heap_adjust(vector<int>& nums, int i, int len)
{
    int child;
    int temp;
    for (; 2 * i + 1 < len; i = child) {
        child = 2 * i + 1;  // 子结点的位置 = 2 * 父结点的位置 + 1
                            // 得到子结点中键值较大的结点
        if (child < len - 1 && nums[child + 1] > nums[child])
            child++;
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if (nums[i] < nums[child]) {
            temp = nums[i];
            nums[i] = nums[child];
            nums[child] = temp;
        }
        else
            break;
    }
}
