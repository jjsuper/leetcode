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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *out;
        ListNode *pout;
        ListNode *tmp;
        pout = new ListNode(0);
        out = pout;
        int c =0;
        int s;
        
        while(l1 && l2)
        {
            s = ( l1->val + l2->val + c ) % 10;
            c = ( l1->val + l2->val + c ) / 10;
            tmp = new ListNode(s);
            pout->next = tmp; 
            
            l1=l1->next;
            l2=l2->next;
            pout=pout->next;
        }
          
        while(l1)
        {
            s = ( l1->val + c ) % 10;
            c = ( l1->val + c ) / 10; 
            
            tmp = new ListNode(s);
            pout->next = tmp; 
            
            l1=l1->next;
            pout=pout->next;
        }     
        
        while(l2)
        {
            s = ( l2->val + c ) % 10;
            c = ( l2->val + c ) / 10; 
            
            tmp = new ListNode(s);
            pout->next = tmp; 
            
            l2=l2->next;
            pout=pout->next;
        }
        
        if(c!=0)
        {
            tmp = new ListNode(c);
            pout->next = tmp;
            pout=pout->next;
        }
        
        
        return out->next;
    }
};