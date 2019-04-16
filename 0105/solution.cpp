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
    
    map<int,int> map_inorder;
    
public:
    
    void add_node(TreeNode* root,int val_preorder){
        

        if( map_inorder[val_preorder] < map_inorder[root->val] ){
            if(root->left == nullptr){
                root->left = new TreeNode(val_preorder);
            }
            else{
                add_node(root->left,val_preorder);
            }
        }
        else{
            if(root->right == nullptr){
                root->right = new TreeNode(val_preorder);
            }
            else{
                add_node(root->right,val_preorder);
            }
        }
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=inorder.size();
        
        if(n==0) return nullptr;
        
        for(int i=0;i<n;i++){
            map_inorder[inorder[i]]=i;
        }
        
        
        TreeNode* ans=new TreeNode(preorder[0]);
        
        for(int i=1;i<n;i++) add_node(ans,preorder[i]);
        
        return ans;
        
    }
};