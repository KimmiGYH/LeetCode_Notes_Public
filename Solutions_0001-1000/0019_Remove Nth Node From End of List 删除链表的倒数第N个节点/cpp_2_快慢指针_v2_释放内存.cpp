#include <iostream>
#include <cassert>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n >= 0);

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p = dummy, *q = dummy;
        for (int i = 0; i < n + 1; i++) {
            assert(q); // q 不为空
            q = q->next;
        }

        while (q) {
            p = p->next;
            q = q->next;
        }

        ListNode *delNode = p->next;
        p->next = p->next->next;
        delete delNode;

        ListNode *retNode = dummy->next;
        delete dummy;

        return retNode;
    }
};