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
    TreeNode* invertTree(TreeNode* root) {
        //reverse error    if root==null, we cannot use root->right
        if(root==NULL) return root;      
        TreeNode* tmp=root->right;
        root->right=invertTree(root->left);
        root->left=invertTree(tmp);
    }
};