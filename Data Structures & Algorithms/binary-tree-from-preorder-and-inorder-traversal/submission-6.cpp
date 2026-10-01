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
    int search(vector<int> inorder,int left,int right,int a){
        for(int i=left;i<=right;i++){
            if(inorder[i]==a){return i;}
        }
        return -1;
    }
    TreeNode* CBT(vector<int>& preorder,vector<int>& inorder,int& preidx,int left,int right){
        if(left>right) return NULL;
        TreeNode*root=new TreeNode(preorder[preidx]);
        int inidx=search(inorder,left,right,preorder[preidx]);
        preidx++;
        root->left=CBT(preorder,inorder,preidx,left,inidx-1);
        root->right=CBT(preorder,inorder,preidx,inidx+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int predix=0;
        return CBT(preorder,inorder,predix,0,preorder.size()-1);
    }
};
