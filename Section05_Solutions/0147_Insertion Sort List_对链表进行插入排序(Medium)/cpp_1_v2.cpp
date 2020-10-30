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
        auto dummy = new ListNode(-1);

        for (auto cur = head; cur;) {
            auto p = dummy, next = cur->next;
            while (p->next && p->next->val <= cur->val) p = p->next;
            
            cur->next = p->next;
            p->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};
