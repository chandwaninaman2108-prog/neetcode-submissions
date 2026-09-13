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
int height(TreeNode* root){
        if(root==NULL) return 0;
        int leftht=height(root->left);
        int rightht=height(root->right);
        return max(leftht,rightht)+1;
    }
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int leftdm=diameterOfBinaryTree(root->left);
        int rightdm=diameterOfBinaryTree(root->right);
        int currdm=height(root->left)+height(root->right);
        return max(max(leftdm,rightdm),currdm);
    }
};
