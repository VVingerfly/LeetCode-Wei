/*
���һ��������������֮���ԭ������һ���ľͳ���������������Ϊ�������С����磺
{ 1, 2, 1 }, { 15, 78, 78, 15 }, { 112 } �ǻ�������,
{ 1, 2, 2 }, { 15, 78, 87, 51 }, { 112, 2, 11 } ���ǻ������С�
���ڸ���һ���������У�����ʹ��һ��ת��������
ѡ�������������ڵ�����Ȼ��������Ƴ������������������������ֵĺͲ��뵽��������֮ǰ��λ��(ֻ����һ����)��
���ڶ�����������Ҫ���������Ҫ���ٴβ������Խ����ɻ������С�

�������� :
����Ϊ���У���һ��Ϊ���г���n(1 �� n �� 50)
�ڶ���Ϊ�����е�n������item[i](1 �� iteam[i] �� 1000)���Կո�ָ���


������� :
���һ��������ʾ������Ҫ��ת������

�������� :
4
1 1 1 3

������� :
	2
*/

#pragma once
#include "../global.h"

#ifdef RUN_NetEase1

#include <iostream>
#include <vector>

using namespace std;

int isHuiWen(const vector<int> &items)
{
	// return -1 : is HunWen xulie
	// return [0~size-1] is not HunWen, return the idx
	int head = 0;
	int rear = items.size() - 1;
	while (head < rear)
	{
		if (items.at(head) != items.at(rear))
		{
			return head;
		}
		head++;
		rear--;
	}
	return -1;
}

void oneOperation(vector<int> &items, int id)
{
	if (id + 1 > items.size() - 1) return;

	int new_num = items.at(id) + items.at(id + 1);
	items.insert(items.begin() + id, new_num);
	items.erase(items.begin() + id + 1);
	items.erase(items.begin() + id + 1);
}

void printVector(const vector<int> &items)
{
	cout <<"vector = [ ";
	for (size_t i = 0; i < items.size(); ++i)
	{
		cout << items.at(i);
		if (i != items.size()-1)
		{
			cout << ", ";
		}
		
	}
	cout <<" ] " << endl;
}



int main()
{
	//int nums[] = { 1, 1, 1, 3 };
	//vector<int> items(nums, nums + 4);
	int num;
	cin >> num;
	vector<int> items;
	for (int i=0; i<num; i++)
	{
		int x;
		cin >> x;
		items.push_back(x);
	}
	
	int cnt = 0;
	while (true)
	{
		int id = isHuiWen(items);
		if (id == -1)
		{
			break;
		}
		oneOperation(items, id);
		printVector(items);
		cnt++;
	}
	cout << "total operations " << cnt << endl;

	return 0;
}

#endif
