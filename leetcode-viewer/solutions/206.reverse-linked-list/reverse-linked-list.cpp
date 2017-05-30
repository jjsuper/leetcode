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
    ListNode* reverseList(ListNode* head) {
        /*
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        
        ListNode *node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        
        
        return node;*/
        if(head==NULL) return head;
        if(head->next==NULL) return head;        
        
        ListNode* nhead=new ListNode(0);
        nhead->next=head;
        
        //ListNode* tail=head;
        ListNode* cur=head->next;
        
        while(cur) {
            head->next=cur->next;
            cur->next=nhead->next;
            nhead->next=cur;
            cur=head->next;
        }
        
        return nhead->next;
    }
};