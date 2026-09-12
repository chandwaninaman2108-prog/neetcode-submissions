/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void pre_o_traversal(TreeNode* root){
        if(root==NULL) return;
        TreeNode* Newnode=root->right;
        root->right=root->left;
        root->left=Newnode;
        pre_o_traversal(root->left);
        pre_o_traversal(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        pre_o_traversal(root);
        return root;
    }
};
