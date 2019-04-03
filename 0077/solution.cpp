class Solution {
    
    vector<vector<int>> ans;
public:
    
    void search(set<int> cand, vector<int> num,int cnt){
        
        if(num.size()==cnt){
            
            ans.push_back(num);
            return ;
        }
        
        for(auto x:cand){
            set<int> next_cand;
            next_cand = set<int>();
            for(auto y:cand){
                if(y>x) next_cand.insert(y);
            }
            if(cand.size() + num.size() < cnt){
                return ;
            }
            next_cand.erase(x);
            vector<int> next_num(0);
            next_num = vector<int>();
            copy(num.begin(), num.end(), back_inserter(next_num));
            next_num.push_back(x);
            search(next_cand,next_num,cnt);
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        set<int> cand;
        
        for(int i=1;i<=n;i++) cand.insert(i);
        

        search( cand,vector<int>(0),k );

        
        return ans;
        
    }
};