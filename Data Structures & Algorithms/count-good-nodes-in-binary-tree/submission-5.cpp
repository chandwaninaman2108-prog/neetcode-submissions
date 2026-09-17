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
    int helper(TreeNode* root,int currmax){
        if(!root) return 0;
        int rootans=root->val>=currmax?1:0;
        if(rootans) currmax=root->val;
        int lans=helper(root->left,currmax);
        int rans=helper(root->right,currmax);
        return rootans+lans+rans;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};
