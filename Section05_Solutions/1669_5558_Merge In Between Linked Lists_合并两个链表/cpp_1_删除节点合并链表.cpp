// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p = list1, *q = list1;
        for (int i = 0; i < a - 1; i++)  p = p->next;
        for (int i = 0; i < b + 1; i++)  q = q->next;
        p->next = list2;
        while (list2->next) list2 = list2->next;
        list2->next = q;
        return list1;
    }
};