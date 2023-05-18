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
        auto slow = head, fast = head;
        while(fast) {
            slow = slow->next, fast = fast->next;
            if (!fast) return NULL;
            fast = fast->next;
            // 如果相遇，让一个指针从相遇点继续走，另一个指针从起点开始走
            if (slow == fast) {
                slow = head;
                while (slow != fast) slow = slow->next, fast = fast->next;
                return slow ;
            }
        }
        return NULL;
    }
};