/**
 * @file Q23_MergeKSortedLists.cpp
 * @author Wei LI (wei587me@163.com)
 * @brief 合并K个升序链表
 * @version 0.1
 * @date 2021-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;


// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


/**
 * @brief 合并K个升序链表
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 * 示例 1：
 * - 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * - 输出：[1,1,2,3,4,4,5,6]
 * - 解释：链表数组如下：
 *     [
 *         1->4->5,
 *         1->3->4,
 *          2->6
 *       ]
 *   将它们合并到一个有序链表中得到。
 *   1->1->2->3->4->4->5->6
 * 
 * 示例 2：
 * - 输入：lists = []
 * - 输出：[]
 * 
 * 示例 3：
 * - 输入：lists = [[]]
 * - 输出：[]
 * 
 * 提示：
 * - `k == lists.length`
 * - `0 <= k <= 10^4`
 * - `0 <= lists[i].length <= 500`
 * - `-10^4 <= lists[i][j] <= 10^4`
 * - `lists[i]` 按 **升序** 排列
 * - `lists[i].length` 的总和不超过 `10^4`
 *
 * @note https://leetcode-cn.com/problems/merge-k-sorted-lists
 */
class A22_MergeKSortedLists
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {

    }
};

int main()
{
    vector<vector<vector<int>>> lists = {
        {{1,4,5},{1,3,4},{2,6}},
        {}
    };
    vector<vector<int>> solutions = {
        {1,1,2,3,4,4,5,6},
        {}
    };

    auto compare_vector = [](const vector<int>& v1, const vector<int>& v2) {
        if (v1.size() != v2.size())
            return false;
        for (size_t i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < lists.size(); i++) {
        A22_MergeKSortedLists solution;
        
    }
    return 0;
}
