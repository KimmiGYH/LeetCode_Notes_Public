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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l > r)  return nullptr;
        if (l == r)  return lists[l];
        if (l + 1 == r)  return mergeTwoLists(lists[l], lists[r]);
        int m = l + (r - l) / 2;
        auto l1 = merge(lists, l, m);
        auto l2 = merge(lists, m + 1, r);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val)  swap(l1, l2);
            tail = tail->next = l1;
            l1 = l1->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};