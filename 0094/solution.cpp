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
    
  void inorder_search(TreeNode* node){
        
    if( node->left==nullptr && node->right==nullptr ){
      ans.push_back(node->val);
            
    }
    else if(node->left==nullptr){
      ans.push_back(node->val);
      inorder_search(node->right);
    }
    else if(node->right==nullptr){
      inorder_search(node->left);
      ans.push_back(node->val);
            
    }
    else{
      inorder_search(node->left);
      ans.push_back(node->val);
      inorder_search(node->right);
    }
        
  }
    
public:
    
  vector<int> inorderTraversal(TreeNode* root) {
        
    if(root==nullptr) return ans;
        
    inorder_search(root);
        
    return ans;
  }
};
