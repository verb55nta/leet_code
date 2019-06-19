class Solution {
public:
    string decodeString(string s) {
        
        string ans;
        
        stack<pair<int,string>> sta;
        

        string tmp;
        int num=0;
        
        for(auto c:s){
            
            if(c>='0' && c<= '9'){
                num=10*num+(int)(c-'0');
            }
            else if(c=='['){
                sta.push( make_pair(num,tmp));
                tmp="";
                num=0;
            }
            else if(c==']'){
                auto p=sta.top();
                for(int i=0;i<p.first;i++){
                    p.second+=tmp;
                }
                sta.pop();
                
                if(sta.size()==0){
                    ans+=p.second;
                    tmp="";
                }
                else{
                    tmp=p.second;
                }
                num=0;
            }
            else{
                tmp+=c;
                num=0;
            }
            
        }

        ans+=tmp;
        
        return ans;
    }
};