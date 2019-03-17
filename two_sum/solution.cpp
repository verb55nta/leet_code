class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                if(nums[i]+nums[j]==target){
                vector<int> ans(2);
                ans[0]=i;
                ans[1]=j;
                return ans;
                }
            }

        }
        return {0,0};
    }
};