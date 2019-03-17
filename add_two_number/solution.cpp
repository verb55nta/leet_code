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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur_ans= new ListNode(0);
        ListNode *fir_ans=cur_ans;
        ListNode *cur_l1=l1;
        ListNode *cur_l2=l2;
        int co=0;
        while( cur_l1->next != NULL && cur_l2->next != NULL ){
            int cal=cur_l1->val + cur_l2->val+co;
            if(cal >= 10){
                cal-=10;
                co=1;
            }
            else{
                co=0;
            }
            cur_ans->val=cal;
            //cout << cur_ans->val << endl;
            ListNode *temp = new ListNode(0);
            cur_ans->next=temp;
            cur_ans=cur_ans->next;
            cur_l1=cur_l1->next;
            cur_l2=cur_l2->next;
        }
        ListNode *rest_l;
        if(cur_l1->next != NULL){
            rest_l=cur_l1;
            co+=cur_l2->val;
        }
        else{
            rest_l=cur_l2;
            co+=cur_l1->val;
        }
        while(rest_l->next != NULL){
            int cal=rest_l->val+co;
            if(cal >= 10){
                cal-=10;
                co=1;
            }
            else{
                co=0;
            }
            cur_ans->val=cal;
            ListNode *temp = new ListNode(0);
            cur_ans->next=temp;
            cur_ans=cur_ans->next;
            rest_l=rest_l->next;
        }
        int cal=rest_l->val+co;
        if(cal >= 10){
            cal-=10;
            ListNode *temp = new ListNode(1);
            cur_ans->next=temp;
        }
        else{
            co=0;
        }
        cur_ans->val=cal;
        
        return fir_ans;
    }
};