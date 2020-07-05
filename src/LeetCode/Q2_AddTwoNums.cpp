/**
 * @file Q2_AddTwoNums.cpp
 * @author Wei LI (lw15@mail.ustc.edu.cn)
 * @brief 两数相加
 * @version 0.1
 * @date 2017-01-05
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Definition for singly-linked list.
 * 
 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief 两数相加
 * 
 * 给出两个 **非空** 的链表用来表示两个非负的整数。
 * 其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 **一位** 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字`0`之外，这两个数都不会以`0`开头。
 * 
 * 示例：
 * - 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * - 输出：7 -> 0 -> 8
 * - 原因：342 + 465 = 807
 * 
 * @note https://leetcode-cn.com/problems/add-two-numbers
 * 
 */
class A2_AddTwoNums
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int value1 = 0;
        int value2 = 0;
        int valSum = 0;
        int carry = 0;  // 进位，0或者1
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* res = new ListNode(0);  // 返回结果是res的下一个节点
        ListNode* h = res;
        while (h1 != nullptr || h2 != nullptr) 
        {
            value1 = (h1 != nullptr) ? h1->val : 0;  // 链表较短，假设值为0，不响应相加结果
            value2 = (h2 != nullptr) ? h2->val : 0;
            valSum = value1 + value2 + carry;
            carry = valSum / 10;
            // cout << "sum=" << valSum << "  carry=" << carry << endl;
            h->next = new ListNode(valSum % 10);
            h = h->next;

            if (h1 != nullptr) h1 = h1->next;
            if (h2 != nullptr) h2 = h2->next;
        }
        if (carry == 1)  // 如果进位为1，需再增加一位数
            h->next = new ListNode(carry);
        
        return res->next;
    }
};


int main()
{
    auto print_list = [](ListNode* it, const string& title) {
        ListNode* l = it;
        cout << title << " ";
        while (l != nullptr) {
            if (l->next == nullptr)
                cout << l->val << endl;
            else cout << l->val << " -> ";
            l = l->next;
        }
    };

    auto test_list = [&](ListNode* l1, ListNode* l2) {
        print_list(l1, "list-1: ");
        print_list(l2, "list-2: ");
    
        A2_AddTwoNums solution;
        ListNode* res = solution.addTwoNumbers(l1, l2);
    
        print_list(res, "list-sum: ");
    };

    {
        ListNode* l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);
    
        ListNode* l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        test_list(l1, l2);
    }
    {
        ListNode* l1 = new ListNode(5);
    
        ListNode* l2 = new ListNode(5);
        
        test_list(l1, l2);
    }

    
    
    return 0;
}
