class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itr_l = lower_bound(nums.begin(),nums.end(),target);
        auto itr_r = upper_bound(nums.begin(),nums.end(),target);
        
        auto l = distance(nums.begin(),itr_l);
        auto r = distance(nums.begin(),itr_r);
        
        if(l==r){
            vector<int> ans{-1,-1};
            return ans;
        }
        else{
            vector<int> ans{l,r-1};
            return ans;
        }
        
    }
};