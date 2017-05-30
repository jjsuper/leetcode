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
    int getMinimumDifference(TreeNode* root) {
        if(root->left) getMinimumDifference(root->left);
        if(prev>-1) diff=min(diff, root->val-prev);
        prev=root->val;
        if(root->right) getMinimumDifference(root->right);
        return diff;
    }
private:
    int diff=INT_MAX;
    int prev=-1;
};