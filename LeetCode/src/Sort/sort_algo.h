/**
* @file Example.c
* @author 高明飞
* @version V1.0
* @date 2015-11-13
*
* @brief 程序的简要说明
*
* @details
* @verbatim
* 程序的详细说明。
*
* 修改记录：
* 2015-11-13 :
*   - 修改记录
*
* @endverbatim
*/
//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Apr/15 10:36:35
// Last Change  : 2017/Apr/15 10:36:37
// Summary      :
//===============================================================
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CSortAlgo
{
public:
	CSortAlgo();
	~CSortAlgo();
	void test_sort();
	void print_nums(const vector<int> &nums);
	void randon_nums(int len);

private:
	void bubble_sort(vector<int> &nums);
	void select_sort(vector<int> &nums);
	void insert_sort(vector<int> &nums);
	void quick_sort(vector<int> &nums, int left, int right);

	void merge_sort(vector<int> &nums, vector<int> &nums_temp, int start_index, int end_index);
	void merge(vector<int> &nums, vector<int> &nums_temp, int start_index, int mid_index, int end_index);
	
	void heap_sort(vector<int> &nums);
	void heap_adjust(vector<int> &nums, int i, int len);

private:
	vector<int> nums_;
};

