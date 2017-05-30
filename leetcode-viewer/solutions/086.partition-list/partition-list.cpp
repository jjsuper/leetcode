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
        if(head==NULL) return head;
        
        ListNode* lhead = new ListNode(0);
        ListNode* ghead = new ListNode(0);
        ListNode* lP=lhead;
        ListNode* gP=ghead;
        
        
        while(head)
        {
            if(head->val<x)
            {
                lP->next=head;
                lP=lP->next;
                head=head->next;
                lP->next=NULL;
            }
            else
            {
                gP->next=head;
                gP=gP->next;
                head=head->next;
                gP->next=NULL;
            }
        }
        
        lP->next=ghead->next;
        
        
        
        return lhead->next;
    }
};