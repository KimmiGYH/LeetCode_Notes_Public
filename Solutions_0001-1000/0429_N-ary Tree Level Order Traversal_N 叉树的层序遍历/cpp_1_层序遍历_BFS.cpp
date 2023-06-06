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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> ans;
            while (sz--) {
                auto t = q.front();
                q.pop();
                ans.push_back(t->val);
                for (auto& c : t->children)
                    q.push(c);
            }
            res.push_back(ans);
        }
        return res;
    }
};