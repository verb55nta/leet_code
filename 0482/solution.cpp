class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        
        string postS;
        
        for(auto c:S){
            
            if(c=='-') continue;
            else if(c>='a' && c<= 'z'){
                postS+=c-('a'-'A');
            }
            else{
                postS+=c;
            }
            
        }
        int mod=postS.size()%K;
        
        string ans;
        
        if(postS.size() <= K){
            for(int i=0;i<postS.size();i++) ans+=postS[i];
            
            return ans;
        }
        
        else if(mod!=0){
            for(int i=0;i<mod;i++){
                ans+=postS[i];
            }
            ans+='-';
        }
        postS=postS.substr(mod);
        
        for(int i=0;i<postS.size()/K;i++){
            for(int j=0;j<K;j++){
                ans+=postS[K*i+j];
            }
            if(i<postS.size()/K-1) ans+='-';
        }
        
        
        return ans;
        
    }
};