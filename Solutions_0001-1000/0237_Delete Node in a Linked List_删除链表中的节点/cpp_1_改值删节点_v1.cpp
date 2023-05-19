// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;
        
        if (node->next == nullptr) {
            delete node;
            node = nullptr;
            return;
        }

        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;

        delete delNode;

        return;
    }
};