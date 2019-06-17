/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    int ans=0;

public:

    TreeNode* convertBST(TreeNode* root) {
        
        if(root==nullptr) return nullptr;

        convertBST(root->right);

        ans+=root->val;
        root->val=ans;

        convertBST(root->left);
        

        return root;
    }
};