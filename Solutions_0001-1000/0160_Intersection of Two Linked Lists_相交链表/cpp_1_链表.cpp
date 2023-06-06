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
        int lenA = 0, lenB = 0;
        ListNode *curA = headA, *curB = headB;
        for (auto p = headA; p; p = p->next) lenA++;
        for (auto p = headB; p; p = p->next) lenB++;
        if (lenA < lenB) {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int diff = lenA - lenB;
        while (diff--)
            curA = curA->next;
        while (curA) {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};