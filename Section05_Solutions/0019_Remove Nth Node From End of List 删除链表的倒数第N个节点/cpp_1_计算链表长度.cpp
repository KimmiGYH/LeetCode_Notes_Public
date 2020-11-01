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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        int size = 0;
        for (auto p= head; p; p = p->next)  size++;

        auto p = head;
        // 找到倒数第(n+1)个点，是正数第(size-n)个点
        // 算个数时不包括虚拟头节点。
        for (int i = 0; i < size - n - 1; i++)  p = p->next;
        p->next = p->next->next;

        return dummy->next;
    }
};