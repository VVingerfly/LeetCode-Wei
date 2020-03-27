
#pragma once
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 两个单链表的交点
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.

 * For example, the following two linked lists:
 * ```
 * A:       a1 -> a2
 *                  \
 *                  c1 -> c2 -> c3
 *                  /
 * B: b1 -> b2 -> b3
 * ```
 * begin to intersect at node c1.
 *

 * @note
 * - If the two linked lists have no intersection at all, return null.
 * - The linked lists must retain their original structure after the function returns.
 * - You may assume there are no cycles anywhere in the entire linked structure.
 * - Your code should preferably run in O(n) time and use only O(1) memory.
 * @see https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 */
class A160_IntersectionOfTwoLinkedLists
{
private:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    /*!
     * @brief Use brief, otherwise the index won't have a brief explanation.
     *

     * @param headA singly linked list A
     * @param headB singly linked list B
     * @return intersection node
     * @note
     * @see https://discuss.leetcode.com/topic/5527/my-accepted-simple-and-shortest-c-code-with-comments-explaining-the-algorithm-any-comments-or-improvements
    */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        if (p1 == NULL || p2 == NULL)
            return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            //
            // Any time they collide or reach end together without colliding
            // then return any one of the pointers.
            //
            if (p1 == p2)
                return p1;

            //
            // If one of them reaches the end earlier then reuse it
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning,
            // they will be equidistant from the collision point.
            //
            if (p1 == NULL)
                p1 = headB;
            if (p2 == NULL)
                p2 = headA;
        }

        return p1;
    }

    void runTest()
    {
        ListNode* headA = NULL;
        for (int i = 0; i < 6; i++)
            insertListHead(headA, i);
        cout << "original list A : ";
        printList(headA);

        ListNode* headB = NULL;
        for (int i = 0; i < 4; i++)
            insertListHead(headB, i);
        cout << "original list B : ";
        printList(headB);

        ListNode* headC = NULL;
        for (int i = 0; i < 3; i++)
            insertListHead(headC, i);
        cout << "original list C : ";
        printList(headC);

        ListNode* p1 = headA;
        while (p1->next != NULL)
            p1 = p1->next;
        p1->next = headC;

        ListNode* p2 = headB;
        while (p2->next != NULL)
            p2 = p2->next;
        p2->next = headC;

        printList(headA);
        printList(headB);

        cout << getIntersectionNode(headA, headB)->val << endl;

        delete p1;
        delete p2;
        delete headA;
        delete headB;
        delete headC;
    }

private:
    void insertListHead(ListNode*& head, int data)
    {
        //创建新节点
        ListNode* p = new ListNode(data);
        if (head == NULL) {
            head = p;
            return;
        }
        p->next = head;
        head = p;
    }
    void printList(ListNode* head)
    {
        ListNode* p = head;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};
