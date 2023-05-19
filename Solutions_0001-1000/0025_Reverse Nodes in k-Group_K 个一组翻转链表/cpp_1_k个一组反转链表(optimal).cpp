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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++;
        if (n < k) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p0 = dummy;
        for (int i = 0; i < n / k; i++) {
            ListNode* pre = nullptr;
            ListNode* cur = p0->next;
            for (int j = 0; j < k; j++) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode* temp = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = temp;
        }
        return dummy->next;
    }
};