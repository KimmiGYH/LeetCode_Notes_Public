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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        for (auto p = headA; p; p = p->next) lenA++;
        for (auto p = headB; p; p = p->next) lenB++;
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int diff = lenA - lenB;
        while(diff--)
            curA = curA->next;
        while (curA != nullptr) {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};