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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy;;) {
            // 先遍历一下 p 后面够不够 k 个元素
            auto q = p;
            for (int i = 0; i < k && q; i++) q = q->next;
            if (!q) break;
            auto a = p->next, b = a->next;
            // 处理内部的边
            for (int i = 0; i < k - 1; i++) {
                auto c = b->next;
                b->next = a;
                a = b, b = c;
            }
            auto t = p->next;
            p->next = a, t->next = b;
            p = t;
        }
        return dummy->next;
    }
};