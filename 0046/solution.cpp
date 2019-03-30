class Solution {
    
    vector< vector< int > > ans;
    
public:
    
    void search(set<int> cand,vector<int> num){
        
        if(cand.size()==0){
            ans.push_back(num);
            return ;
        }
        
        for(auto n:cand){
            set<int> next_cand;
            next_cand = set<int>();

            for(auto nn:cand) next_cand.insert(nn);
            next_cand.erase(n);
            vector<int> next_num;
            next_num = vector<int>();
            copy(num.begin(),num.end(),back_inserter(next_num));
            next_num.push_back(n);
            
            search(next_cand,next_num);
            
        }        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        set<int> cand;
        for(auto n:nums) cand.insert(n);
        
        search(cand,vector<int>(0));
        
        return ans;
    }
};