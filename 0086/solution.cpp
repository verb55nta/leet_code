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
    
    ListNode* partition(ListNode* head, int x) {
        
        if(head == nullptr) return head;
        
        if(head->next == nullptr) return head;
        
        ListNode *bef=nullptr,*bef_head=nullptr;
        ListNode *af=nullptr,*af_head=nullptr;
        
        
        while( head != nullptr ){
            
            if(head->val < x){
                if(bef==nullptr){
                    bef = new ListNode(head->val);
                    bef_head=bef;
                }
                else{
                    bef->next = new ListNode(head->val);
                    bef=bef->next;
                }
            }
            else{
                if(af==nullptr){
                    af = new ListNode(head->val);
                    af_head=af;
                }
                else{
                    af->next = new ListNode(head->val);
                    af=af->next;

                }

            }
            head=head->next;
            
        }
        if(bef== nullptr) return af_head;
        bef->next=af_head;
        return bef_head;
    }
};