//===============================================================
// Author       : Wei Li (lw15@mail.ustc.edu.cn)
// Created Date : 2017/Jan/5 19:46:00
// Last Change  : 2017/Jan/5 19:46:03
// Summary      : Use hash(unordered_map) for quick find operation
//===============================================================

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class A2_AddTwoNums
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        /*
        ListNode* res;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        while(h1!=NULL)
        {
        cout<<h1->val<<"  "<<h2->val<<endl;
        h1 = h1->next;
        h2 = h2->next;
        }
        res = new ListNode(3);
        res->next = new ListNode(5);
        cout<<"here"<<res->val<<endl;
        cout<<"here"<<res->next->val<<endl;
        */

        int value0 = 0;
        int value1 = 0;
        int value = 0;
        ListNode* res = NULL;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* h3 = res;
        int cnt = 0;
        while (h1 != NULL && h2 != NULL) {
            value0 = (h1->val + h2->val + value) % 10;
            value1 = (h1->val + h2->val + value) / 10;

            // cout<<"value "<<value1<<"  "<<value0<<endl;
            if (cnt == 0)
                h3 = new ListNode(value0);
            else {
                h3->next = new ListNode(value0);
                h3 = h3->next;
            }

            if (value1 != 0)
                value = value1;
            else
                value = 0;
            // cout<<"val-"<<cnt<<" "<<h3->val<<endl;

            h1 = h1->next;
            h2 = h2->next;
            cnt++;
        }

        while (h1 != NULL) {
            value1 = (h1->val + value) / 10;
            value0 = (h1->val + value) % 10;
            h3->next = new ListNode(value0);
            if (value1 != 0)
                value = value1;
            else
                value = 0;
            h1 = h1->next;
            h3 = h3->next;
        }
        while (h2 != NULL) {
            value1 = (h2->val + value) / 10;
            value0 = (h2->val + value) % 10;
            h3->next = new ListNode(value0);
            if (value1 != 0)
                value = value1;
            else
                value = 0;
            h2 = h2->next;
            h3 = h3->next;
        }
        value1 = (value) / 10;
        value0 = (value) % 10;
        // cout<<"value here "<<value<<"  "<<value1<<"  "<<value0<<endl;
        if (value1 != 0) {
            h3->next = new ListNode(value0);
            h3->next = new ListNode(value1);
        }
        else if (value0 != 0)
            h3->next = new ListNode(value0);

        ListNode* p1q = res;
        while (p1q != NULL) {
            cout << "value " << p1q->val << endl;
            p1q = p1q->next;
        }

        return res;
    }
};

int main()
{
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(5);
    l1->next = new ListNode(4);
    l2->next = new ListNode(6);
    l1->next->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // int nums[2][3] = { {2, 4, 3}, {5, 6, 4} };
    // for (int i = 0; i < 3; i++)
    //{
    //	l1->val = nums[0][i];
    //	l2->val = nums[1][i];
    //	l1 = l1->next;
    //	l2 = l2->next;
    //}
    ListNode* it = NULL;

    A2_AddTwoNums solution;
    ListNode* res = solution.addTwoNumbers(l1, l2);
    it = res;
    while (it != NULL) {
        cout << it->val << " -> ";
        it = it->next;
    }
    cout << endl;
    return 0;
}