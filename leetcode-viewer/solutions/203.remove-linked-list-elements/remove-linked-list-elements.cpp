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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead;
        ListNode* last;
        ListNode* cur;
        
        newhead->next=head;
        last=newhead;
        cur=head;
        
        while(cur)
        {
            if(cur->val==val)
            {
                last->next=cur->next;
                delete cur;
                cur=last->next;
            }
            else
            {
                cur=cur->next;
                last=last->next;
        
            }
        }
        
        
        return newhead->next;
    }
};