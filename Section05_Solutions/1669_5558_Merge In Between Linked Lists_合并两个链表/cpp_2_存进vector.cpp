#include <iostream>
#include <vector>

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<ListNode*> v;
        ListNode *cur = list1;
        while (cur != nullptr) {
            v.push_back(cur);
            cur = cur->next;
        }
        cur = list2;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        v[a - 1]->next = list2;
        cur->next = v[b + 1];
        return list1;
    }
};