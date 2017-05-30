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
        if(!head) return NULL;
        ListNode* nhead=new ListNode(0);
        if(nhead==NULL) cout << "nhead->next NULL" << endl;
        cout << nhead->val;
        
        
        nhead->next=head;
        
        
        ListNode* cur=head;
        head=nhead;
        
        while(cur&&cur->next) {
            if(cur->next->val==cur->val) {
                cout << "in" << endl;
                while(cur->next && cur->next->val==cur->val) cur=cur->next;
                ListNode* tail=cur->next;
                cur->next=NULL;
                cur=head->next;
                head->next=tail;
                while(cur) {
                    ListNode* tmp=cur;
                    cur=cur->next;
                    delete tmp;
                    cout << "delete" << endl;
                }
                cur=tail;
                
                if(tail==NULL) cout << "tail NULL" << endl;
            }
            else {
                cout << "out" << endl;
                head=head->next;
                cur=cur->next;
            }
        }
        
        if(nhead==NULL) cout << "nhead->next NULL" << endl;
        
        cout << nhead->val;
        
        return nhead->next;
    }
};