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
    ListNode* insertionSortList(ListNode* head) {

        ListNode *dummy = new ListNode(0); 
        ListNode *cur = head;
        ListNode *pre = dummy;
        ListNode *next = nullptr;

        while(cur != nullptr)
        {
            while(pre->next && pre->next->val <= cur->val) pre = pre->next;
            next = cur->next;

            // 将 cur 插到 pre 和 p->next 之间
            cur->next = pre->next;
            pre->next = cur;

            cur = next;

            pre = dummy;
        }
        return dummy->next;
    }
};