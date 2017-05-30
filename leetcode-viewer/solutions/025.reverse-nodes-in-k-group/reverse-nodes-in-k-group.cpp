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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k<2) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* start=dummy;
        ListNode* cur=head;
        ListNode* end=head;
        int cnt=0;
        
        while(end) {
            end=end->next;
            cnt++;
            if(cnt==k) {
                cnt=0;
                ListNode* nstart=start->next;
                
                cur=nstart->next;
                while(cur!=end) {
                    nstart->next=cur->next;
                    cur->next=start->next;
                    start->next=cur;
                    cur=nstart->next;
                }
                
                start=nstart;
            }
        }
        
    
        return dummy->next;
    }
};