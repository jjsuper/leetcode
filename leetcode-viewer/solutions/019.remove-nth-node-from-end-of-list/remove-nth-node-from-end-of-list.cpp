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
        ListNode* nhead;
        nhead->next=head;
        ListNode* last;
        last=nhead;
        ListNode* cur;
        cur=head;
        
        
        for(int i=0;i<n;++i)
        {
            cur=cur->next;
        }
        
        while(cur!=NULL)
        {
            last=last->next;
            cur=cur->next;
        }
        
        ListNode* tmp;
        
        tmp=last->next;
        last->next=tmp->next;
        delete tmp;
        
        
        return nhead->next;
    }
};