class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode *temp1 = cur->next;
            ListNode *temp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp1;
            temp1->next = temp2;
            cur = temp1;
        }
        return dummy->next;
    }
};