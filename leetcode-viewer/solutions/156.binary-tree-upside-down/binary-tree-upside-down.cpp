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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* pre=NULL;
        TreeNode* cur=root;
        TreeNode* right=NULL;
        TreeNode* next=NULL;
        
        while(cur) {
            next=cur->left;
            cur->left=right;
            right=cur->right;
            cur->right=pre;
            pre=cur;
            cur=next;
        }
        
        return pre;
    }
};