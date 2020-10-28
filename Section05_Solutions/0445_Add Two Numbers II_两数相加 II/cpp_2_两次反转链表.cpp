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

    ListNode* reverse(ListNode* head) {
        auto a = head, b = head->next;
        while (b) {
            auto c = b->next;
            b->next = a; // b->next指向a
            a = b, b = c;
        }
        head->next = nullptr;
        return a;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        auto head = new ListNode(-1);
        int t = 0;
        while (l1 || l2 || t) {
            if (l1) t += l1->val, l1 = l1->next;
            if (l2) t += l2->val, l2 = l2->next;
            // 实现边插边翻转
            auto cur = new ListNode(t % 10);
            t /= 10;
            cur->next = head->next;
            head->next = cur;
        }
        return head->next;
    }
};