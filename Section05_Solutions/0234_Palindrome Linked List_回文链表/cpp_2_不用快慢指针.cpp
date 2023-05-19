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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n <= 1) return true;

        // 找中点
        int half = n / 2;
        auto a = head;
        for (int i = 0; i < n - half; i ++ ) a = a->next; // 或者写成 i < (n+1)/2 - 1

        // 反转后半段链表
        auto b = a->next;
        for (int i = 0; i < half - 1; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }

        // 判断是会否是回文
        auto p = head, q = a;
        bool success = true;
        for (int i = 0; i < half; i ++ ) {
            if (p->val != q->val) {
                success = false;
                break;
            }
            p = p->next;
            q = q->next;
        }

        auto tail = a;
        b = a->next;
        // 将链表恢复原状
        for (int i = 0; i < half - 1; i ++ ) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }

        tail->next = nullptr;
        return success;
    }
};
