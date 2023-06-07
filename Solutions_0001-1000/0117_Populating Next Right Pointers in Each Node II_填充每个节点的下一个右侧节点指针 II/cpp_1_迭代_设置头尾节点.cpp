/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* cur = root;
        while (cur) {
            Node* head = new Node(-1);//下一层的head
            Node* tail = head;
            for (auto p = cur; p; p = p->next) {
                if (p->left)
                    tail = tail->next = p->left;
                if (p->right)
                    tail = tail->next = p->right;
            }
            cur = head->next;//下一层的第一个节点
        }
        return root;
    }
};