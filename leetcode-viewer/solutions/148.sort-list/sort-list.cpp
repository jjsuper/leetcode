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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        fast=slow->next;
        slow->next=NULL;
        
        return merge(sortList(head), sortList(fast));
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* tmp=new ListNode(0);
        ListNode* head=tmp;
        
        while(l1!=NULL && l2!=NULL) {
            if(l1->val<l2->val) {
                tmp->next=l1;
                l1=l1->next;
            }
            else {
                tmp->next=l2;
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        
        if(l1!=NULL) 
            tmp->next=l1;
        else
            tmp->next=l2;
        
        return head->next;
    }
};