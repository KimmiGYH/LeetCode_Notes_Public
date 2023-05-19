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

// -----自己写的代码----------

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1);;
        dummy->next = head;
        int size = 0;
        for (auto p = head; p; p = p->next)
            size ++;
        // 要删除的是第 size-n+1 个节点，即例子中的第4个节点
        int len = size - n; //被删节点的下标 3，第3个节点又是被删节点的前一个节点
        ListNode* p = dummy;
        while (--len >= 0)
            p = p->next;
        p->next = p->next->next;
        return dummy->next;
    }
};

// --- 写成 for 循环也可以 ---
        ListNode* p = dummy;
        for (int i = 0; i < len; i++)
                    p = p->next;