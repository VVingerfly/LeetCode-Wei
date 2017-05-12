//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Jan/5 19:45:26
// Last Change  : 2017/Jan/5 19:45:29
// Summary      :
//===============================================================

#include "Q2_AddTwoNums.h"
#include <iostream>
using namespace std;
//#define DEBUG_Q2


void testQ2()
{
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(5);
	l1->next = new ListNode(4);
	l2->next = new ListNode(6);
	l1->next->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	//int nums[2][3] = { {2, 4, 3}, {5, 6, 4} };
	//for (int i = 0; i < 3; i++)
	//{
	//	l1->val = nums[0][i];
	//	l2->val = nums[1][i];
	//	l1 = l1->next;
	//	l2 = l2->next;
	//}
	ListNode *it = NULL;

	A2_AddTwoNums solution;
	ListNode * res = solution.addTwoNumbers(l1, l2);
	it = res;
	while (it != NULL)
	{
		cout << it->val << " -> ";
		it = it->next;
	}
	cout << endl;
}

#ifdef DEBUG_Q2
int main()
{
	testQ2();
	return 0;
}
#endif
