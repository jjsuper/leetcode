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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        
        if(headA==NULL || headB==NULL) return NULL;
        
        int lenA=0, lenB=0;
        
        while(pA!=NULL)
        {
            lenA++;
            pA=pA->next;
        }
        
        while(pB!=NULL)
        {
            lenB++;
            pB=pB->next;
        }
        
        pA=headA;
        pB=headB;
        
        
        
        while(lenA>lenB)
        {
            pA=pA->next;
            lenA--;
        }
        
        while(lenA<lenB)
        {
            pB=pB->next;
            lenB--;
        }
        
        while(pA!=NULL&&pB!=NULL)
        {
            if(pA==pB) return pA;
            
            pA=pA->next;
            pB=pB->next;
        }
        
        
        
        return NULL;
    }
};