/*
[LeetCode] 19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = new ListNode(), *remove_ptr = new ListNode(), *ans = new ListNode();
        ans->next = head;
        cur->next = ans;
        remove_ptr->next = ans;

        int cnt = 0;
        while(cur != nullptr && remove_ptr != nullptr) {
            if(cnt > n)
                remove_ptr = remove_ptr->next;
            cur = cur->next;
            cnt++;
        }
        remove_ptr->next = remove_ptr->next->next;
        return ans->next;
    }
};