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
private:
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    void traverse(TreeNode* root) {
        if(root==NULL) return;
        traverse(root->left);
        if(first==NULL && prev->val>root->val) first=prev;
        if(first!=NULL && prev->val>root->val) second=root;
        prev=root;
        traverse(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(first->val, second->val);
    }
};