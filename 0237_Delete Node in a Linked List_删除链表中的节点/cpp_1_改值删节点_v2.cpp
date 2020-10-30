// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // 将值改成下个节点的值
        node->next = node->next->next; // 将下个节点删掉
    }
};
