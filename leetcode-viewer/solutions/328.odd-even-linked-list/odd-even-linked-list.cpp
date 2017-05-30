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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        
        ListNode* cur=head->next->next;
        int flag=1;
        
        ListNode* evenHead=head->next;
        ListNode* oddTail=head;
        ListNode* evenTail=head->next;
        
        while(cur)
        {
            if(flag%2==1)
            {
                oddTail->next=cur;
                oddTail=cur;
            }
            else
            {
                evenTail->next=cur;
                evenTail=cur;
            }
            
            cur=cur->next;
            ++flag;
        }
        
        oddTail->next=evenHead;
        evenTail->next=NULL;
        
        return head;
    }
};