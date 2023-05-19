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
        if (!head) return head;
        ListNode* a = head;
        ListNode* b = a->next;
        while (b) {
            ListNode*c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = nullptr;
        return a;
    }
};

/* 
a     b    c
pre  cur  nxt
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = nullptr;
        return pre;        
    }
};