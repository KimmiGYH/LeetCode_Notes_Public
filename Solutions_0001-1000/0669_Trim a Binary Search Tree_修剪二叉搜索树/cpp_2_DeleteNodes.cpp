/* 内存回收：https://youtu.be/L_t2x3nH61k?t=378
The previous solution has potential memory leak for languages without garbage collection.

Here’s the full program to delete trimmed nodes.
*/
// Author: Huahua
#include <iostream>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    
    // With cleanup -> no memory leak
    TreeNode*& trimBST(TreeNode*& root, int L, int R) {
        if(!root) return root;
        
        if(root->val < L) {            
            auto& result = trimBST(root->right, L, R);
            deleteTree(root->left);
            delete root;
            root=nullptr;
            return result;
        } else if(root->val > R) {
            auto& result = trimBST(root->left, L, R);
            deleteTree(root->right);
            delete root;
            root=nullptr;
            return result;
        } else {
            // recusively trim left/right subtrees
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
    
    void deleteTree(TreeNode* &root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=nullptr;
    }
};
 
void PrintTree(TreeNode* root) {
    if(!root) {
        cout<<"null ";
        return;
    };
    if(!root->left && !root->right) {
        cout<<root->val<<" ";
    } else {
        cout<<root->val<<" ";
        PrintTree(root->left);
        PrintTree(root->right);
    }
}
 
 
int main()
{
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    PrintTree(root);
    std::cout<<std::endl;
    
    TreeNode* t = Solution().trimBST(root, 3, 4);
    PrintTree(t);
    std::cout<<std::endl;
 
    // Original root was deleted
    PrintTree(root);
    std::cout<<std::endl;
    
    return 0;
}
/*
Example output

1
2
3
2 1 3 
3 
null
*/