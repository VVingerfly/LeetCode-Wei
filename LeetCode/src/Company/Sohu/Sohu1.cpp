#include "SohuDefs.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Use brief, otherwise the index won't have a brief explanation.
 *
 * Detailed explanation.
 * @note 
 * @see 
 */
class CSohu1
{
public:
	struct ListNode
	{
		int value;
		ListNode *next;
	};
	ListNode* reverseList(ListNode* head);
	ListNode* reverseListRecursive(ListNode* head);

	void insertListHead(ListNode * &head, int data);
	void  printList(ListNode* head);
	void runTest()
	{
		ListNode * head = NULL;
		for (int i = 0; i < 9; i++)
			insertListHead(head, i);
		cout << "original list: ";
		printList(head);

		head = reverseList(head);
		cout << "reversed list: ";
		printList(head);

		head = reverseListRecursive(head);
		cout << "reversed list: ";
		printList(head);
	}

};

CSohu1::ListNode* CSohu1::reverseList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* prev = head;
	ListNode* curr = head->next;
	ListNode* temp = head->next->next;
	//  prev -> curr -> temp
	//   a   ->  b   ->  c   ->  d
	//      <-  curr->next = prev
	while (curr)
	{
		temp = curr->next;  //temp��Ϊ�м�ڵ㣬��¼��ǰ������һ���ڵ��λ��  
		curr->next = prev;  //��ǰ���ָ��ǰһ���ڵ�  
		prev = curr;        //ָ�����  
		curr = temp;        //ָ����ƣ�������һ���ڵ�  
	}

	head->next = NULL;     //while�����󣬽���ת������һ���ڵ㣨����תǰ�ĵ�һ�����head����������ΪNULL  
	return prev;
}

CSohu1::ListNode* CSohu1::reverseListRecursive(ListNode* head)
{
	if (head == NULL || head->next == NULL) //�ݹ���ֹ����:�ҵ��������һ�����  
		return head;
	else
	{
		ListNode * newhead = reverseListRecursive(head->next);  //�ȷ�ת�����������������������㿪ʼ��ת��������ǰ  
		head->next->next = head;    //����һ��������ָ��ǰһ�����  
		head->next = NULL;			//��ԭ������ǰһ�����ָ���һ������ָ���ϵ�Ͽ�  
		return newhead;
	}
}

/*!
* @brief ����һ���½ڵ㵽������(��������ͷ��)
* @param head head pointer of the list
* @param data the data to insert before head
* @return  NULL
* @note
*/
void CSohu1::insertListHead(ListNode * &head, int data)
{
	//�����½ڵ�  
	ListNode * p = new ListNode;
	p->value = data;
	p->next = NULL;

	if (head == NULL)
	{
		head = p;
		return;
	}
	p->next = head;
	head = p;
}

void CSohu1::printList(ListNode* head)
{
	ListNode * p = head;
	while (p != NULL)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

#ifdef RUN_Sohu1
int main()
{
	CSohu1 res;
	res.runTest();
	return 0;
}
#endif


