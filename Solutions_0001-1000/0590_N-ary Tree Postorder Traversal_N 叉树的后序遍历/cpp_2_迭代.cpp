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
    vector<int> postorder(Node* root) {
        stack<Node*> stk;
        vector<int> res;
        if (!root) return res;
        stk.push(root);
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            res.push_back(t->val);
            // 前序：中左右 ->【中右左】-> 后序：左右中
            for (int i = 0; i < t->children.size(); i++)
                stk.push(t->children[i]);
            // for (auto& c : t->children)
            //     stk.push(c);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};