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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), tail = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail = tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }

        if (l1)  tail->next = l1;
        if (l2)  tail->next = l2;
        return dummy->next;
    }
};

// ---------------------------------

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* x, ListNode* y) {//list1 = x, list2 = y
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(x && y) {
            if (x->val < y->val) {
                tail = tail->next = x;
                x = x->next;
            } else {
                tail = tail->next = y;
                y = y->next;
            }
        }
        if (x) tail->next = x;
        if (y) tail->next = y;
        return dummy->next;
    }
};