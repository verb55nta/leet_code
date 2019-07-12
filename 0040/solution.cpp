class Solution {
    
    
public:
    
    vector<vector<int>> search(map<int,int>& m,int target,int index){
        

        vector<vector<int>> ret;
        
        int i=0;
        
        for(auto c=begin(m);c!=end(m);c++,i++){
            //cout << c.first << endl;
            if(c->second==0) continue;
            if(i<index) continue;
            
            if(c->second>0){

                if(target == c->first){
                    ret.push_back( {c->first} );
                }
                else if(target-c->first>0){
                    c->second--;
                    vector<vector<int>> v=search(m,target-c->first,i);                    
                    for(auto &&vv:v){
                        //cout << c->first << endl;
                        vv.push_back(c->first);
                    }
                    copy(begin(v),end(v),back_inserter(ret));
                    c->second++;
                }
            }
            
        }
        
        
        //cout << endl;
        return ret;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        //sort(begin(candidates),end(candidates));
        map<int,int> m;
        for(auto c:candidates) {
            if(m.find(c)==end(m)) m[c]=1;
            else m[c]++;
        }
        
       
        
        vector<vector<int>> ans=search(m,target,0);
        
        
            
        return ans;
    }
};