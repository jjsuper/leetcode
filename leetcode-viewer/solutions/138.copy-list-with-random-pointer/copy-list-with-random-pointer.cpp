/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> hash;
        
        //step 1 copy
        RandomListNode* node=head;
        while(node) {
            RandomListNode* tmp=new RandomListNode(node->label);
            hash[node]=tmp;
            node=node->next;
        }
        
        
        //step 2 assign pointer
        node=head;
        while(node) {
            hash[node]->next=hash[node->next];
            hash[node]->random=hash[node->random];
            node=node->next;
        }

        
        return hash[head];
    }
};