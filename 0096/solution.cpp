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
    
    vector<int> ans;
    
public:
    
    bool inorder_search(TreeNode* node){
        
        if(node == nullptr) return true;
        
        bool flag=true;
        
        flag = flag & inorder_search(node->left);
        
        if(ans.size() >0 && ans[ans.size()-1] >= node->val) return false;
        ans.push_back(node->val);
        
        flag = flag & inorder_search(node->right);
        
        return flag;
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        return inorder_search(root);
        
    }
};