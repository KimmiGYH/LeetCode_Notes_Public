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
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr)
            return pre;
        ListNode* nxt = cur->next;
        cur->next = pre;
        return reverse(cur, nxt);
    }

    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* pre = nullptr;
        // ListNode* cur = head;
        return reverse(nullptr, head);
    }
};