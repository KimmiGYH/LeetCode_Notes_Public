
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
    void reorderList(ListNode* head) {
        if (!head) return;
        // 求总长度
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        // 找中点 mid
        auto mid = head;
        for (int i = 0; i < (n+1)/2 - 1; i++) mid = mid->next;

        // 反转后半段链表
        auto tail = mid;
        for (auto p = mid, q = mid->next; q;) {
            auto next = q->next;
            q->next = p, p = q, q = next;
            tail = p;
        }
        
        // 将后半段交替插入前半段
        for (auto p = head, q = tail; q != mid;) {
            auto next = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next, q = next;
        }

        // 判断尾节点
        if (n % 2) mid->next = nullptr;
        else mid->next->next = nullptr;
    }
};