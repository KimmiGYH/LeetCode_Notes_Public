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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next; //保存cur->next
                cur->next = tmp->next;
                delete tmp; //删掉该节点
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// ----------------------------------------------------

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next; //也可以还原这步
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// ----------------------------------------------------

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                cur->next = cur->next->next; //直接裸写也可以
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};