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
        Node* source = root;
        while (root->left) {
            for (auto p = root; p; p = p->next) {
                p->left->next = p->right;
                if (p->next)
                    p->right->next = p->next->left;
            }
            root = root->left;
        }
        return source;
    }
};

// -------------2023年6月7日--------------

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node* cur = root;
        while (cur->left) {
            for (auto p = cur; p; p = p->next) {
                p->left->next = p->right;
                if (p->next)
                    p->right->next = p->next->left;
            }
            cur = cur->left;
        }
        return root;
    }
};