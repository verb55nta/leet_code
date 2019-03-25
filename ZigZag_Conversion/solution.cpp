class Solution {
public:
    string convert(string s, int numRows) {
        
             
        int rep= 2*numRows-2;
        
        if(rep==0) return s;
        
        int div= s.size()/rep;
        int mod= s.size()%rep;
        
        string ans;

        vector< vector<char> > substr(div+1,vector<char>(rep,0));
        
        
        
        for(int i=0;i<div+1;i++){
            if(i==div){
                if(mod==0) continue;
                for(int j=0;j<mod;j++){
                    if(j==0){

                        substr[i][0]=s[rep*i+j];
                    }
                    else{

                        substr[i][(j<=rep/2?2*j-1:2*(rep-j))]=s[rep*i+j];
                    }
                }
            }
            else{
                for(int j=0;j<rep;j++){
                    if(j==0){

                        substr[i][0]=s[rep*i+j];
                    }
                    else{

                        substr[i][(j<=rep/2?2*j-1:2*(rep-j))]=s[rep*i+j];
                    }
                }    
            }
            
        }

        for(int i=0;i<numRows;i++){
            if(i==0){
                for(auto x:substr){
                    if(x[i] != 0){

                        ans+=x[i];
                    }
                }
            }
            else if(i==numRows-1){
                for(auto x:substr){
                    if(x[rep-1] != 0){

                        ans+=x[rep-1];
                    }
                }
            }
            else{
                for(auto x:substr){
                    if(x[2*i-1] != 0){

                        ans+=x[2*i-1];
                    }
                    if(x[2*i] != 0){

                        ans+=x[2*i];
                    }
                }
            }
            
        }

        
        
        return ans;
    }
};