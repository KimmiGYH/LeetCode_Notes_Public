// 时间复杂度分析：整个链表只扫描一遍，所以时间复杂度是 O(n)

#include <iostream>
using namespace std;

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return head;
        auto cur = head;
        for (auto p = head->next; p; p = p->next)
            if (p->val != cur->val)
                cur = cur->next = p;
        cur->next = nullptr;
        return head;
    }
};