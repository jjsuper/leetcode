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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        
        while(l1) {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2=l2->next;
        }
        
        
        int c=0, sum=0;
        while(!s1.empty()&&!s2.empty()) {
            sum=(s1.top()+s2.top()+c)%10;
            c=(s1.top()+s2.top()+c)/10;
            s3.push(sum);
            s1.pop();
            s2.pop();
        }
        
        while(!s1.empty()) {
            sum=(s1.top()+c)%10;
            c=(s1.top()+c)/10;
            s3.push(sum);
            s1.pop();
        }
        while(!s2.empty()) {
            sum=(s2.top()+c)%10;
            c=(s2.top()+c)/10;
            s3.push(sum);
            s2.pop();
        }
        if(c) s3.push(c);
        /*
        while(!s3.empty()) {
            cout << s3.top() << ' ';
            s3.pop();
        }*/
        
        
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        while(!s3.empty()) {
            ListNode* tmp=new ListNode(s3.top());
            s3.pop();
            cur->next=tmp;
            cur=cur->next;
        }
        
        return head->next;
    }
};