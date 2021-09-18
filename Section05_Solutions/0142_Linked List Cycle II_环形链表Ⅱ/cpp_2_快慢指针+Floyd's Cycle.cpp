#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        auto s = head, f = head;
        while(f) {
            s = s->next, f = f->next;
            if (!f) return NULL;
            f = f->next;
            // 如果相遇，让一个指针从相遇点继续走，另一个指针从起点开始走
            if (s == f) {
                s = head;
                while (s != f) s = s->next, f = f->next;
                return s;
            }
        }
        return NULL;
    }
};