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
    void reorderList(ListNode* head) {
        int len = 0, n = 0;
        for (auto p = head; p; p = p->next) len ++;
        n = len / 2 + 1;
        
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (--n) cur = cur->next;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        while (pre->next) {
            ListNode* a = head->next;
            ListNode* b = pre->next;
            head->next = pre;
            pre->next = a;
            head = a;
            pre = b;
        }
    }
};