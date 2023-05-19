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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        for (auto p = head; p; p = p->next)
            len ++;
        int n = len / 2 + 1;
        ListNode* cur = head;
        while (--n)
            cur = cur->next;
        return cur;
    }
};