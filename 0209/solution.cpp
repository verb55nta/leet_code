class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==0) return 0;
        
        if(n==1){
            if(nums[0] >= s) return 1;
            else return 0;
        }
        
        int left=0;
        int right=0;
        
        int judge=0;
        
        int ans=n;
        
        while( right < n){
            //cout << ans << "," << judge << endl;
            if(judge<s){
                judge+=nums[right];
                right++;

            }
            else{
                ans=min(ans,right-left);
                judge-=nums[left];
                left++;
            }
            
        }
        if(ans==n && judge < s ) return 0;
        //cout << ans << "," << judge << endl;
        while( left < right && judge>=s){
            ans=min(ans,right-left);
            judge-=nums[left];
            left++;
        }
        
        
        return ans;
        
    }
};