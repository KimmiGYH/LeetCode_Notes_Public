/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    queue<Node*> q;
    int maxDepth(Node* root) {
        int depth = 0;
        if (root) q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto t = q.front();
                q.pop();
                for (auto& c : t->children)
                    q.push(c);
            }
            depth ++;
        }
        return depth;
    }
};