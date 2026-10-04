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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //We will use level-o-traversal
        if(!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* build(stringstream& ss){
        string val;
        getline(ss,val,',');
        if(val=="#") return nullptr;
        TreeNode* root=new TreeNode(val==""?0:stoi(val));
        root->left=build(ss);
        root->right=build(ss);
        return root;
    }
    TreeNode* deserialize(string data) {
          stringstream ss(data);
          return build(ss);
    }

};
