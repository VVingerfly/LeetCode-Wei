#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * }; 
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        ListNode* p = head;
        while (p) {
            nums.push_back(p->val);
            p = p->next;
        }
        std::reverse(nums.begin(), nums.end());
        return nums;
    }

    vector<int> reversePrint2(ListNode* head) {
        int cnt = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            cnt++;
        }
        vector<int> nums(cnt);
        p = head;
        while (p) {
            nums[--cnt] = p->val;
            p = p->next;
        }
        return nums;
    }
};