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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        // p 为 cur, q 为 delNode
        for (auto p = dummy; p; p = p->next) {
            auto q = p->next;
            while (q && q->val == val)
                q = q->next;
            p->next = q;
        }
        return dummy->next;
    }
};

// ------------释放内存----------------

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy; p; p = p->next) {
            auto q = p->next;
            while (q && q->val == val)  q = q->next;
            p->next = q;
        }
        auto retNode = dummy->next;
        delete dummy;
        return retNode;
    }
};