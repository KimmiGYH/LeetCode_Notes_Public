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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // q 快指针， p 慢指针
        ListNode *p = dummy, *q = dummy;
        for (int i = 0; i < n; i++) // q 先走 n 步
            q = q->next;
        while (q->next) { // 一起走
            p = p->next;
            q = q->next;    
        }
        p->next = p->next->next;
        return dummy->next;
    }
};

// -------p 为 slow，q 为 fast-----------


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(n--)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
