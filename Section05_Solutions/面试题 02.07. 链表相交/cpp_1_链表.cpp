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
        // 分别求链表 A、B 的长度
        int lenA = 0, lenB = 0;
        for (auto p = headA; p; p = p->next) lenA++;
        for (auto p = headB; p; p = p->next) lenB++;
        // 让 curA 为最长链表的头，lenA 为其长度
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // 求长度差 并让curA和curB在同一起点上（末尾位置对齐）
        int diff = lenA - lenB;
        while(diff--)
            curA = curA->next;
        // 遍历 curA 和 curB，遇到相同则直接返回
        while (curA != nullptr) {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};