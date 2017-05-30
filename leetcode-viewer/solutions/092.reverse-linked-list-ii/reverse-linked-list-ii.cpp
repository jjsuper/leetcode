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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *nhead = new ListNode(0);
        nhead->next=head;
        ListNode *beginNode=nhead;
        ListNode *endNode;
        
        
        
        for(int i=m; i>1; i--)
        {
            beginNode=beginNode->next;
        }
        
        
        endNode=beginNode->next;
        
        //cout << beginNode->val << " " << endNode->val << endl;
        print(nhead);
        for(int i=m; i<n; ++i)
        {
            ListNode *tmp=endNode->next;
            endNode->next=tmp->next;
            tmp->next=beginNode->next;
            beginNode->next=tmp;
            print(nhead);
        }
        
        
        
        
        
        
        return nhead->next;
    }
private:
    void print(ListNode* head)
    {
        while(head)
        {
            cout << head->val << " ";
            head=head->next;
        }
        cout << endl;
    }
    
    
};