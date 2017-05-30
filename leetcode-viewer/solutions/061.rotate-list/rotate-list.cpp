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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* nhead=head, *tail=head;
        int len=1;
        while(tail->next!=NULL) {
            tail=tail->next;
            len++;
        }
        tail->next=head;
        
        if(k%=len) {
            for(int i=0; i<len-k; ++i) tail=tail->next;
        }
        nhead=tail->next;
        tail->next=NULL;
        
        return nhead;
    }
};