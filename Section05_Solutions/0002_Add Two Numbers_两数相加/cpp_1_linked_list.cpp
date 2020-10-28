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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 虚拟头节点是"和的链表"中的, cur是当前和的尾节点是哪个点
        auto dummy = new ListNode(-1), cur = dummy;
        int t = 0; // 进位
        while(l1 || l2 || t) {
            if (l1)  t += l1->val, l1 = l1->next;
            if (l2)  t += l2->val, l2 = l2->next;
            // 如果和大于等于10，则保留个位数字, 是 t 的个位数字
            // 另外别忘记更新 cur = cur->next
            cur = cur->next = new ListNode(t % 10); // 为 val = t%10 的节点开辟内存
            t /= 10;
        }
        return dummy->next;
    }
};

