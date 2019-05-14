class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        if(nums.size()==0) return vector<vector<int>>(1,vector<int>());
        
        vector<vector<int>> ans;
        
        vector<int> next_nums;
        
        copy( begin(nums)+1,end(nums), back_inserter(next_nums) );
        
        for(auto x: subsets( next_nums )){
            
            ans.push_back( x );
            auto k=x;
            k.push_back(nums[0]);
            
            ans.push_back( k );
        }
        
        return ans;
        
    }
};