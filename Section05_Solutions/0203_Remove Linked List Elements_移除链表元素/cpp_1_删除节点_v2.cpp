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
        for (auto cur = dummy; cur; cur = cur->next) {
            auto delNode = cur->next;
            while (delNode && delNode->val == val)  delNode = delNode->next;
            cur->next = delNode;
        }
        return dummy->next;
    }
};