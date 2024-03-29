#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) { //m是left, n是right
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto a = dummy;
        // a 跳 m-1 次，使得 a 就位
        for (int i = 0; i < m - 1; i++)  a = a->next;
        auto b = a->next, c = b->next;
        // 第一步：翻转 n-m 条边
        for (int i = 0; i < n - m; i++) {
            auto d = c->next;
            c->next = b; 
            b = c, c = d;
        }
        // 第二步：
        // 让 m (m其实就是 a->next) 指向 c
        // 让 a 指向 n (n其实就是b);
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};

// --------------------------------------------------

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* a = dummy;
        for (int i = 0; i < left - 1; ++i)
            a = a->next;
        auto b = a->next, c = b->next;
        for (int i = 0; i < right - left; ++i) {
            auto d = c->next;
            c->next = b;
            b = c, c = d;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};