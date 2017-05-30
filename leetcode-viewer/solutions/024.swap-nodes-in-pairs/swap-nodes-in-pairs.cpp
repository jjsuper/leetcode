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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        
        ListNode* cur, * pre;
        
        pre=newhead;
        cur=head;
        
        while(pre->next!=NULL&&cur->next!=NULL)
        {
            pre->next=cur->next;
            cur->next=pre->next->next;
            pre->next->next=cur;
            pre=cur;
            cur=cur->next;
        }
        
        
        return newhead->next;
    }
};