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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, bool (*)(ListNode*, ListNode*)> heap([](ListNode* a, ListNode* b){return a->val > b->val;});

        for(int i=0; i<lists.size(); ++i) {
            if(lists[i]!=NULL) heap.push(lists[i]);
        }  
        
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        while(!heap.empty()) {
            cout << heap.top()->val;
            
            ListNode* tmp=heap.top();
            heap.pop();
            cur->next=tmp;
            cur=tmp;
            
            if(tmp->next!=NULL) {
                tmp=tmp->next;
                //cur->next=NULL;
                heap.push(tmp);
            } 
        }
    

        return dummy->next;
    }
};