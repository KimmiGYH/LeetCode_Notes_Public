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
    ListNode* reverse(ListNode *dummy, ListNode *cur) {
        if (cur->next == nullptr || cur->next->next == nullptr)
            return dummy->next;
        ListNode *a = cur->next, *b = a->next;
        cur->next = b;
        a->next = b->next;
        b->next = a;
        return reverse(dummy, a);
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        return reverse(dummy, dummy);
    }
};