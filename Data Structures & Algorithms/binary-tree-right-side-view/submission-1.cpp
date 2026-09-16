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
    vector<int> rightSideView(TreeNode* root) {
        //Level order Traversal
        if(!root) return {};
        vector<int> RightNodes;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    continue;
                }
                else break;
            }
            if(q.front()==NULL){RightNodes.push_back(curr->val);}
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        return RightNodes;
    }
};
