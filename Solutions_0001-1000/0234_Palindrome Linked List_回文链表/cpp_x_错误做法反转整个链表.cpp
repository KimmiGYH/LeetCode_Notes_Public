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
//错误代码❌

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* head2 = reverseLinkedList(head);
        for (auto p = head, q = head2; p && q; p = p->next, q = q->next){
            if (p->val != q->val)
                return false;
        }
        head = reverseLinkedList(head2);
        return true;
    }
};
/*Wrong Answer: [1,1,2,1]
Output: true
Expected: False

分析：
把原链表反转了之后，节点的指向都反了，所以 for 循环里 p 节点只运行了一次，即当 p = head 时，再后面就是指向空指针了。
*/