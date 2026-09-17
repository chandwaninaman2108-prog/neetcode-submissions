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
    vector<int> goodnodes;
    int helper(TreeNode* root,int currmax){
        if(root==NULL) return 0;
        int rootans=0;
        if(root->val>=currmax){rootans=1;currmax=root->val;}
        int lans=helper(root->left,currmax);
        int rans=helper(root->right,currmax);
        return rootans+lans+rans;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};
