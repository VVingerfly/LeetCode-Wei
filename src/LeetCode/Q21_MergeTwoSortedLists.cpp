/**
 * @file Q21_MergeTwoSortedLists.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 合并两个有序链表
 * @version 0.1
 * @date 2021-02-28
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
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
 * @brief 合并两个有序链表
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 *
 * 示例 1：
 * - 输入：l1 = [1,2,4], l2 = [1,3,4]
 * - 输出：[1,1,2,3,4,4]
 *
 * 示例 2：
 * - 输入：l1 = [], l2 = []
 * - 输出：[]
 *
 * 示例 3：
 * - 输入：l1 = [], l2 = [0]
 * - 输出：[0]
 *
 * 提示：
 * - 两个链表的节点数目范围是 [0, 50]
 * `-100 <= Node.val <= 100`
 * - l1 和 l2 均按 **非递减顺序** 排列
 *
 * @note https://leetcode-cn.com/problems/merge-two-sorted-lists
 */
class A21_MergeTwoSortedLists
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1 == nullptr && l2 == nullptr) 
            return nullptr;

        ListNode* res_list = new ListNode();
        ListNode* res = res_list;
        ListNode* list1 = l1;
        ListNode* list2 = l2;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                res->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                res->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            res = res->next;
        }
        if (list1)
            res->next = list1;
        if (list2)
            res->next = list2;

        return res_list->next;
    }
};

int main()
{
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

    auto gen_list = [](const vector<int>& vals) -> ListNode* {
        ListNode* list;
        if (vals.empty())
            return nullptr;

        list = new ListNode(vals[0]);
        ListNode* ptr = list;
        for (size_t i = 1; i < vals.size(); i++) {
            ptr->next = new ListNode(vals[i]);
            ptr = ptr->next;
        }
        return list;
    };

    vector<vector<int>> vals_1 = { { 1, 2, 4 }, {} };
    vector<vector<int>> vals_2 = { { 1, 3, 4 }, { 0 } };
    vector<vector<int>> results = { { 1, 1, 2, 3, 4, 4 }, { 0 } };

    for (size_t i = 0; i < results.size(); i++) {
        A21_MergeTwoSortedLists solution;

        ListNode* list_1 = gen_list(vals_1[i]);
        ListNode* list_2 = gen_list(vals_2[i]);
        print_list(list_1);
        print_list(list_2);

        auto res = solution.mergeTwoLists(list_1, list_2);

        cout << "Test case " << i + 1 << "/" << results.size() << " -> ";
        if (compare_list(results[i], res))
            cout << "Pass" << endl;
        else {
            cout << "Fail" << endl;
            cout << "  Returned Result: ";
            print_list(res);
            cout << "  Expected Result: ";
            for (const auto& v : results[i])
                cout << v << " ";
            cout << endl;
        }
    }
    return 0;
}
