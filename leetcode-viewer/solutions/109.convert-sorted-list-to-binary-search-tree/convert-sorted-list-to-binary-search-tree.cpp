/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if(head==tail) return NULL;
        if(head->next==tail) {
            TreeNode* tmp=new TreeNode(head->val);
            return tmp;
        }
                
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=tail && fast->next!=tail) {
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortedListToBST(head, slow);
        root->right=sortedListToBST(slow->next, tail);
        return root;
    }
};