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
    void pre_o_swap(TreeNode* root){
        if(root==NULL) return;
        TreeNode* newnode=root->left;
        root->left=root->right;
        root->right=newnode;
        pre_o_swap(root->left);
        pre_o_swap(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        pre_o_swap(root);
        return root;
    }
};
