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
	void merge(vector<int> &nums, vector<int> &nums_temp, int start_index, int mid_index, int end_index);
	void merge_sort(vector<int> &nums);
	void heap_sort(vector<int> &nums);

private:
	vector<int> nums_;
};

