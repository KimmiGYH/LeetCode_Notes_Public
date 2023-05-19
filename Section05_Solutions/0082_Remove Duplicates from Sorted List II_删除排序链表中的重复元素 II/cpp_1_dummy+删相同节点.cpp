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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next && p->next->next) {
            int value = p->next->val;
            if (p->next->next->val == value) {
                while (p->next && p->next->val == value)
                    p->next = p->next->next;
            } else p = p->next;
        }
        return dummy->next;
    }
};
// 【82. 删除排序链表中的重复元素【基础算法精讲 08】】 【精准空降到 04:38】 https://www.bilibili.com/video/BV1VP4y1Q71e/?share_source=copy_web&vd_source=672840fcf5c68492bb4e1f49d5c87506&t=278