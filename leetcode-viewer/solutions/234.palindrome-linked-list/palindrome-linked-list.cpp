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
    bool isPalindrome(ListNode* head) {
                if(!head || !head->next) return true;
        ListNode * fast = head, * slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * head1 = head;
        ListNode * head2 = invertList(slow->next);//reverse last half Linked list 
        int res = true;
        while(head2){
            if(head1->val != head2->val){
                res = false;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        slow->next = invertList(slow->next);//recover
        return res;
    }

    ListNode* invertList(ListNode* head){
        ListNode * p = nullptr, * cur = head;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = p;
            p = cur;
            cur = tmp;
        }
        return p;
    
        
        
    }
};