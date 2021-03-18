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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)  return head;
        auto a = head, b = a->next;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = nullptr;
        return a;
    }
};

