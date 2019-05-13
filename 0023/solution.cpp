/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        map< int,int,greater<int> > m;
        
        if(lists.size()==0) return nullptr;
        
        for(auto x:lists){
            ListNode* cur=x;
            while(cur!=nullptr){

                if(m.find(cur->val) == end(m) ) m[cur->val]=1;
                else m[cur->val]++;
                cur=cur->next;
            }
        }
        
        ListNode* ans=nullptr;

        for(auto x:m){
            //cout << x.first << "," << x.second << endl;
            int k=x.second;
            while(k>0){
                
                if(ans==nullptr){
                    auto tmp=new ListNode(x.first);
                    ans=tmp;
                }
                else{
                    auto tmp=new ListNode(x.first);
                    tmp->next=ans;
                    ans=tmp;
                }
                k--;
            }
            
        }
        //cout << "debug" << endl;
        return ans;
        
    }
};