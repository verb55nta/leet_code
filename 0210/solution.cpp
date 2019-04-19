class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        set<int> nodes_set;
        for(int i=0;i<numCourses;i++) nodes_set.insert(i);
        
        map<int,set<int> > edges_in_map;
        map<int,set<int> > edges_out_map;
        
        for(auto c:prerequisites){
            nodes_set.erase(c.first);
            edges_in_map[c.first].insert(c.second);
            edges_out_map[c.second].insert(c.first);
        }
        
        //for(auto c:nodes_set) cout << c << endl;
        
        while(nodes_set.size()>0){
            int node= *(nodes_set.begin());
            nodes_set.erase(node);
            ans.push_back(node);
            for(auto c: edges_out_map[node]){
                edges_out_map[node].erase(c);
                edges_in_map[c].erase(node);
                if(edges_in_map[c].size()==0){
                    edges_in_map.erase(c);
                    nodes_set.insert(c);
                }
            }
            
        }
        
        //for(auto c:ans) cout << c << endl;

        //cout << edges_in_map.size() << endl;
        
        if(edges_in_map.size()>0 ) return vector<int>();
        
        return ans;
        
        
    }
};