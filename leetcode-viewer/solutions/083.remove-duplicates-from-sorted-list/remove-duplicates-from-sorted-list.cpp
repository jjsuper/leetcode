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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        
        int cur=head->val;
        int last=head->val-1;
        
        ListNode* curNode=head;
        ListNode* lastNode;
        
        while(curNode)
        {
            cur=curNode->val;
            if(cur==last)
            {
                ListNode* tmp=curNode;
                
                curNode=curNode->next;
                lastNode->next=curNode;
                delete tmp;
                
            }
            else
            {
                last=cur;
                lastNode=curNode;
                curNode=curNode->next;
            }

        }
        
        return head;
    }
};