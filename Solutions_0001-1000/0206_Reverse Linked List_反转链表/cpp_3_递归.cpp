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
 
// 另外一种与双指针法不同思路的递归写法：从后往前翻转指针指向。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        // 递归调用，翻转第二个节点开始往后的链表
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};