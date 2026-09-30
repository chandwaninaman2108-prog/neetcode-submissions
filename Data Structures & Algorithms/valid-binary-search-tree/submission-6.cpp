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
    int maxel=INT_MIN;
    bool ok=true;
    void InOrderTrav(TreeNode* root){
        if(root==NULL) return;
        InOrderTrav(root->left);
        if(root->val<=maxel) ok=false;
        maxel=root->val;
        InOrderTrav(root->right);
    }
    bool isValidBST(TreeNode* root) {
        InOrderTrav(root);
        return ok;
    }
};
