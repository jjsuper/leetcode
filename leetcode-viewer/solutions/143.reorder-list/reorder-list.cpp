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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return;
        
        //step 1 cut mid
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast && fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        
        ListNode* mid=slow->next;
        slow->next=NULL; //?
           
        print(head);
        print(mid);     
        
        
        
        //step 2 reverse 2nd
        ListNode* p1=mid, *p2, *p3;
        if(p1->next) {
            p2=p1;
            p3=p1->next;
            p2->next=NULL;
            while(p3) {
                p2=p3;
                p3=p3->next;
                p2->next=p1;
                p1=p2;
            }
        }
        
        print(head);
        print(p1);
        
        
        //step 3 merge
        ListNode* h1=head, *h2=p1, *t1;
        
        while(h2) {
            t1=h1->next;
            h1->next=h2;
            h2=h2->next;
            h1->next->next=t1;
            h1=t1;
        }
        
        print(head);
        
    }
private:
    void print(ListNode* head) {
        while(head) {
            cout << head->val << " ";
            head=head->next;
        }
        cout << endl;
    }
};