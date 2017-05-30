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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL) return head;
        
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        ListNode* cur=head;
        ListNode* prev=newhead;
        
        
        while(cur) {
           ListNode* tmp=newhead;
           while(tmp->next!=cur&&tmp->next->val<cur->val) tmp=tmp->next;
           
           if(tmp!=prev) {
               prev->next=cur->next;
               cur->next=tmp->next;
               tmp->next=cur;
               cur=prev->next;
           }
           else {
               cur=cur->next;
               prev=prev->next;
           }

        }
        

        return newhead->next;
    }
};