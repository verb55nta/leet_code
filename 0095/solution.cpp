class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTreesUtil(1, n);
    }
    
    vector<TreeNode*> generateTreesUtil(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTreesUtil(start, i - 1);
            vector<TreeNode*> right = generateTreesUtil(i + 1, end);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};