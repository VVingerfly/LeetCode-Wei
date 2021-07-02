/**
 * @file Q19_RemoveNthNodeFromEndOfList.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 删除链表的倒数第 N 个结点
 * @version 0.1
 * @date 2021-02-23
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * @brief 删除链表的倒数第 N 个结点
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 * 进阶：你能尝试使用一趟扫描实现吗？
 *
 * 示例 1：
 * - 输入：head = [1,2,3,4,5], n = 2
 * - 输出：[1,2,3,5]
 *
 * 示例 2：
 * - 输入：head = [1], n = 1
 * - 输出：[]
 *
 * 示例 3：
 * - 输入：head = [1,2], n = 1
 * - 输出：[1]
 *
 * 提示：
 * - 链表中结点的数目为 sz
 * - `1 <= sz <= 30`
 * - `0 <= Node.val <= 100`
 * `1 <= n <= sz`
 *
 * @note https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
 */
class A19_RemoveNthNodeFromEndOfList
{
public:
    ListNode* removeNthFromEnd_naive(ListNode* head, int n)
    {
        // 计算链表的长度
        int len = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            len++;
        }

        // 增加一个哑节点（dummy node），避免对头节点进行特殊的判断
        // ListNode* pre_list = new ListNode(0, head);
        ListNode* pre_list = new ListNode(0);
        pre_list->next = head;
        ptr = pre_list;
        for (int i = 0; i < len-n; i++) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;

        return pre_list->next;
    }

    // 双指针法/快慢指针法，让前面的指针先移动n步，之后前后指针共同移动，当前面的指针到尾部时，后面的指针刚好到倒数第n个节点
    ListNode* removeNthFromEnd_fast_slow_pointers(ListNode* head, int n)
    {
        ListNode* pre_list = new ListNode(0, head);
        ListNode* slow = pre_list;
        ListNode* fast = pre_list->next;

        //快指针前进n步
        for (int i = 0; i < n; ++i)
            fast = fast->next;

        //快指针在第n个，慢指针在第0个，两个指针一起向后移动，直到快指针到链表尾部
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return pre_list->next;
    }
};

int main()
{
    vector<pair<vector<int>, int>> inputs = { { { 1, 2, 3, 4, 5 }, 2 }, { { 1 }, 1 }, { { 1, 2 }, 1 } };
    vector<vector<int>> results = { { 1, 2, 3, 5 }, {}, { 1 } };
    auto compare_list = [](const vector<int>& nums, ListNode* list) {
        ListNode* head = list;
        int cnt = 0;
        while (head) {
            int val = head->val;
            if (cnt >= nums.size())
                return false;
            if (val != nums[cnt])
                return false;
            head = head->next;
            cnt++;
        }
        if (cnt != nums.size())
            return false;
        return true;
    };

    auto print_list = [](ListNode* list) {
        ListNode* head = list;
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };

    for (size_t i = 0; i < inputs.size(); i++) {
        auto nums = inputs[i].first;
        ListNode* list = new ListNode(nums[0]);
        ListNode* list_tmp = list;
        for (size_t j = 1; j < nums.size(); ++j) {
            list_tmp->next = new ListNode(nums[j]);
            list_tmp = list_tmp->next;
        }
        int n = inputs[i].second;
        // print_list(list);

        A19_RemoveNthNodeFromEndOfList solution;
        // ListNode* res = solution.removeNthFromEnd_fast_slow_pointers(list, n);
        ListNode* res = solution.removeNthFromEnd_naive(list, n);

        if (compare_list(results[i], res))
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "Returned Result: ";
            for (ListNode* tmp = res; tmp; tmp = tmp->next)
                cout << tmp->val << " ";
            cout << endl;
            cout << "Expected Result: ";
            for (const auto& v : results[i])
                cout << v << " ";
            cout << endl;
        }
    }

    return 0;
}
