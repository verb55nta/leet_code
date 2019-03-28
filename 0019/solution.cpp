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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* current = head;
        if(current == NULL) return NULL;

        vector<ListNode*> l;
        while(current != NULL){
            //cout << current->val << endl;
            l.push_back(current);
            current = current->next;
                        
        }
        
        reverse(l.begin(),l.end());
        
        if(l.size() == 1) return NULL;
        
        if(l.size() == n){
            head = l[n-1]->next;
        }
        else{
            l[n]->next = l[n-1]->next;
        }
        
        
        return head;
    }
};