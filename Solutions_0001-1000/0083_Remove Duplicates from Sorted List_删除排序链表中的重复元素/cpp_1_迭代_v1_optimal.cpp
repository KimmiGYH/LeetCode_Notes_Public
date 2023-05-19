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

// 可以保留 head，所以无需设 dummy node
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return head;
        ListNode* p = head;
        while (p->next) {
            if (p->val == p->next->val)
                p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};