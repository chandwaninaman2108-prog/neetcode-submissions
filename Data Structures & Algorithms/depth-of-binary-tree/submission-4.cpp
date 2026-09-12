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
    int level_o_ct(TreeNode* root){
        if(root==NULL) return 0;
        int ct=1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(!q.empty()){ct++; q.push(NULL); continue;}
                else{break;}}
            if(curr->right!=NULL){q.push(curr->right);}
            if(curr->left!=NULL){q.push(curr->left);}
        }
        return ct;
    }
    int maxDepth(TreeNode* root) {
        return level_o_ct(root);
    }
};
