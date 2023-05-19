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
        ListNode *dummy = new ListNode(-1);
        while (head)
        {
            ListNode *next = head->next;
            ListNode *p = dummy;
            while (p->next && p->next->val <= head->val) p = p->next;

            // 将 head 插到 p 和 p->next 之间
            head->next = p->next;
            p->next = head;

            head = next;
        }
        return dummy->next;
    }
};
