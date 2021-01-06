// 5-2 | 16:10
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
 

ListNode* createLinkedList(int arr[], int n) {
    if (n == 0)  return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for (int i = 1; i < n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curNode = head;
    while (curNode != NULL) {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;

    return;
}

ListNode* deleteLinkedList(ListNode* head) {
    ListNode* curNode = head;
    while (curNode != NULL) {
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    
    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = Solution().reverseList(head);
    printLinkedList(head2);

    deleteLinkedList(head2);
    return 0;
}

/* Output:
1 -> 2 -> 3 -> 4 -> 5 -> NULL
5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/