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
public:
    
    map<int,vector<int>> node_map;
    
    int depth_max=0;
    
    void search(int level,TreeNode* node){
        
        if(node==nullptr) return;
        
        search(level+1,node->left);
        
        if(level>depth_max) depth_max=level;
        
        node_map[level].push_back(node->val);
        
        search(level+1,node->right);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==nullptr) return vector<vector<int>>();
        
        search(0,root);
        //cout << "depth_max:" << depth_max << endl;
        vector< vector<int> > ans(depth_max+1);
        
        for(int i=0;i<depth_max+1;i++){
            
            copy(node_map[i].begin(),node_map[i].end(),back_inserter(ans[i]) );
            
        }
        
        return ans;
    }
};