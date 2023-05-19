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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *cur = head;
        ListNode *dummy = new ListNode(-1);

        while(cur)
        {
            ListNode *p = dummy;
            ListNode *next = cur->next;
            while(p->next && p->next->val <= cur->val) p = p->next;

            // 将 cur 插到 p 和 p->next 之间
            cur->next = p->next;
            p->next = cur;

            cur = next;
        }
        return dummy->next;
    }
};