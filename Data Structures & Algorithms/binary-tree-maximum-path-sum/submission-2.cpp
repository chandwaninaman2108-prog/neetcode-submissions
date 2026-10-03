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
    // We have to initialize a global variable maxsum and then apply a dfs algorithm.
    int maxsum=INT_MIN;
    int DFS(TreeNode* root){
        if(root==NULL) return 0;
        int l=max(0,DFS(root->left));// negative elements can be excluded.
        int r=max(0,DFS(root->right));
        maxsum=max(maxsum,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int k=DFS(root);
        return maxsum;
    }
};
