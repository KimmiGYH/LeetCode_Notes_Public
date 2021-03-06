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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                // 删除 cur->next
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
                // delNode->next = NULL;
            }
            else
                cur = cur->next;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;        
    }
};