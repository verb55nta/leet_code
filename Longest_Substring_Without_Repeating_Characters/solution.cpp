class Solution {
public:
    int lengthOfLongestSubstring(string s) {
int n=s.size();
        unordered_set<char> str_set;
        int ans=0;
        int i=0;
        int j=0;
        while(i<n && j<n){
            
            if(str_set.find(s[j]) == str_set.end() ){
                str_set.insert(s[j]);
                j++;
                ans = max(ans,j-i);
            }
            else{
                str_set.erase(s[i]);
                i++;
            }
            
        }
        return ans;
    }
};