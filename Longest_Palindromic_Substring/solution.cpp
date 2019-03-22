class Solution {
public:
    string longestPalindrome(string s) {
        vector< vector<int> > dp(1001,vector<int>(1001,0));
        
        string ans;
        
               
        if(s.size()==1){
            return s;
        }
        
        int ans_s=0;
        int ans_l=0;
        
        for(int len=1;len<=s.size();len++){
            for(int start=0;start<s.size()-len+1;start++){
                if(len==1){
                    dp[len][start]=1;
                    //ans=s[start];
                    ans_s=start;
                    ans_l=len;
                }
                else if(len==2){
                    if(start+1 >= s.size()) continue;
                    if( s[start]==s[start+1] ){
                        dp[len][start]=1;
                        //ans=s.substr(start,len);
                        ans_s=start;
                        ans_l=len;
                    }
                }
                else{
                    if(start+1 >= s.size() || start+len-1 >= s.size()) continue;
                    if( dp[len-2][start+1]==1 && s[start]==s[start+len-1] ){
                        dp[len][start]=1;
                        //ans=s.substr(start,len);
                        ans_s=start;
                        ans_l=len;
                    }
                }
            }
        }
        
        return s.substr(ans_s,ans_l);
    }
};